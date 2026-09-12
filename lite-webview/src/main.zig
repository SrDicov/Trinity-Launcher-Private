const std = @import("std");

extern "c" fn mcperun_webview_run(
    start: [*:0]const u8,
    end_prefix: [*:0]const u8,
) ?[*:0]const u8;

pub fn main(init: std.process.Init) !void {
    const io = init.io;
    const allocator = init.arena.allocator();
    const args = std.process.Args.toSlice(init.minimal.args, allocator) catch return std.process.exit(255);
    if (args.len != 3) {
        return std.process.exit(255);
    }

    const start_z = allocator.dupeZ(u8, args[1]) catch return std.process.exit(255);
    const end_z = allocator.dupeZ(u8, args[2]) catch return std.process.exit(255);

    const matched = mcperun_webview_run(start_z.ptr, end_z.ptr);
    if (matched) |url| {
        var stdout_buffer: [1024]u8 = undefined;
        var writer = std.Io.File.stdout().writer(io, &stdout_buffer);
        writer.interface.print("{s}\n", .{std.mem.span(url)}) catch {};
        writer.flush() catch {};
    }
    return std.process.exit(0);
}
