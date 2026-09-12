const std = @import("std");

const gtk_include_paths = [_][]const u8{
    "/usr/include/webkitgtk-4.1",
    "/usr/include/gtk-3.0",
    "/usr/include/at-spi2-atk/2.0",
    "/usr/include/at-spi-2.0",
    "/usr/include/dbus-1.0",
    "/usr/lib64/dbus-1.0/include",
    "/usr/include/gio-unix-2.0",
    "/usr/include/pango-1.0",
    "/usr/include/harfbuzz",
    "/usr/include/fribidi",
    "/usr/include/atk-1.0",
    "/usr/include/cairo",
    "/usr/include/freetype2",
    "/usr/include/pixman-1",
    "/usr/include/gdk-pixbuf-2.0",
    "/usr/include/libpng16",
    "/usr/include/webp",
    "/usr/include/libsoup-3.0",
    "/usr/include/libmount",
    "/usr/include/blkid",
    "/usr/include/glib-2.0",
    "/usr/lib64/glib-2.0/include",
};

const gtk_libs = [_][]const u8{
    "webkit2gtk-4.1",
    "gtk-3",
    "gdk-3",
    "pangocairo-1.0",
    "pango-1.0",
    "harfbuzz",
    "z",
    "atk-1.0",
    "cairo-gobject",
    "cairo",
    "gdk_pixbuf-2.0",
    "soup-3.0",
    "gmodule-2.0",
    "gio-2.0",
    "javascriptcoregtk-4.1",
    "gobject-2.0",
    "glib-2.0",
};

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const module = b.createModule(.{
        .root_source_file = b.path("src/main.zig"),
        .target = target,
        .optimize = optimize,
        .link_libc = true,
        .link_libcpp = true,
    });

    module.addCSourceFile(.{
        .file = b.path("src/webview.cc"),
        .flags = &.{ "-std=c++11" },
    });

    module.addIncludePath(.{ .cwd_relative = "src" });

    for (gtk_include_paths) |p| {
        module.addIncludePath(.{ .cwd_relative = p });
    }
    for (gtk_libs) |lib| {
        module.linkSystemLibrary(lib, .{});
    }

    const exe = b.addExecutable(.{
        .name = "lite-webview",
        .root_module = module,
    });
    b.installArtifact(exe);

    const run_cmd = b.addRunArtifact(exe);
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run lite-webview");
    run_step.dependOn(&run_cmd.step);
}
