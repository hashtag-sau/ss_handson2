/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 20th sep, 2024.
============================================================================
*/

//mknod my_fifo_pipe p
//  ls -l my_fifo_pipe 
// prw-rw-r-- 1 h1n1cov h1n1cov 0 Sep 21 16:25 my_fifo_pipe

// mkfifo my_fifo
// ls -l my_fifo
// prw-rw-r-- 1 h1n1cov h1n1cov 0 Sep 21 16:25 my_fifo

// strace mknod my_fifo_pipe2 p
// execve("/usr/bin/mknod", ["mknod", "my_fifo_pipe2", "p"], 0x7ffc5fd44840 /* 57 vars */) = 0
// brk(NULL)                               = 0x55d473b25000
// arch_prctl(0x3001 /* ARCH_??? */, 0x7ffd8fc04550) = -1 EINVAL (Invalid argument)
// mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f57802f3000
// access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
// openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=71363, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 71363, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f57802e1000
// close(3)                                = 0
// openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libselinux.so.1", O_RDONLY|O_CLOEXEC) = 3
// read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=166280, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 177672, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f57802b5000
// mprotect(0x7f57802bb000, 139264, PROT_NONE) = 0
// mmap(0x7f57802bb000, 106496, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6000) = 0x7f57802bb000
// mmap(0x7f57802d5000, 28672, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x20000) = 0x7f57802d5000
// mmap(0x7f57802dd000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x27000) = 0x7f57802dd000
// mmap(0x7f57802df000, 5640, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f57802df000
// close(3)                                = 0
// openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
// read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P\237\2\0\0\0\0\0"..., 832) = 832
// pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
// pread64(3, "\4\0\0\0 \0\0\0\5\0\0\0GNU\0\2\0\0\300\4\0\0\0\3\0\0\0\0\0\0\0"..., 48, 848) = 48
// pread64(3, "\4\0\0\0\24\0\0\0\3\0\0\0GNU\0I\17\357\204\3$\f\221\2039x\324\224\323\236S"..., 68, 896) = 68
// newfstatat(3, "", {st_mode=S_IFREG|0755, st_size=2220400, ...}, AT_EMPTY_PATH) = 0
// pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
// mmap(NULL, 2264656, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f578008c000
// mprotect(0x7f57800b4000, 2023424, PROT_NONE) = 0
// mmap(0x7f57800b4000, 1658880, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7f57800b4000
// mmap(0x7f5780249000, 360448, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1bd000) = 0x7f5780249000
// mmap(0x7f57802a2000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x215000) = 0x7f57802a2000
// mmap(0x7f57802a8000, 52816, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f57802a8000
// close(3)                                = 0
// openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpcre2-8.so.0", O_RDONLY|O_CLOEXEC) = 3
// read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=613064, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 615184, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f577fff5000
// mmap(0x7f577fff7000, 438272, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000) = 0x7f577fff7000
// mmap(0x7f5780062000, 163840, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6d000) = 0x7f5780062000
// mmap(0x7f578008a000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x94000) = 0x7f578008a000
// close(3)                                = 0
// mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f577fff3000
// arch_prctl(ARCH_SET_FS, 0x7f577fff3c40) = 0
// set_tid_address(0x7f577fff3f10)         = 24278
// set_robust_list(0x7f577fff3f20, 24)     = 0
// rseq(0x7f577fff45e0, 0x20, 0, 0x53053053) = 0
// mprotect(0x7f57802a2000, 16384, PROT_READ) = 0
// mprotect(0x7f578008a000, 4096, PROT_READ) = 0
// mprotect(0x7f57802dd000, 4096, PROT_READ) = 0
// mprotect(0x55d472222000, 4096, PROT_READ) = 0
// mprotect(0x7f578032d000, 8192, PROT_READ) = 0
// prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
// munmap(0x7f57802e1000, 71363)           = 0
// statfs("/sys/fs/selinux", 0x7ffd8fc04590) = -1 ENOENT (No such file or directory)
// statfs("/selinux", 0x7ffd8fc04590)      = -1 ENOENT (No such file or directory)
// getrandom("\x79\xf8\x50\x7c\xf5\x76\xd0\x77", 8, GRND_NONBLOCK) = 8
// brk(NULL)                               = 0x55d473b25000
// brk(0x55d473b46000)                     = 0x55d473b46000
// openat(AT_FDCWD, "/proc/filesystems", O_RDONLY|O_CLOEXEC) = 3
// newfstatat(3, "", {st_mode=S_IFREG|0444, st_size=0, ...}, AT_EMPTY_PATH) = 0
// read(3, "nodev\tsysfs\nnodev\ttmpfs\nnodev\tbd"..., 1024) = 424
// read(3, "", 1024)                       = 0
// close(3)                                = 0
// access("/etc/selinux/config", F_OK)     = -1 ENOENT (No such file or directory)
// openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=5712208, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 5712208, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f577fa80000
// close(3)                                = 0
// mknodat(AT_FDCWD, "my_fifo_pipe2", S_IFIFO|0666) = 0
// close(1)                                = 0
// close(2)                                = 0
// exit_group(0)                           = ?
// +++ exited with 0 +++

// strace mkfifo my_fifo2
// execve("/usr/bin/mkfifo", ["mkfifo", "my_fifo2"], 0x7ffc6735e288 /* 57 vars */) = 0
// brk(NULL)                               = 0x555a4d217000
// arch_prctl(0x3001 /* ARCH_??? */, 0x7ffd443c2aa0) = -1 EINVAL (Invalid argument)
// mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f2a2c328000
// access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
// openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=71363, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 71363, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f2a2c316000
// close(3)                                = 0
// openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libselinux.so.1", O_RDONLY|O_CLOEXEC) = 3
// read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=166280, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 177672, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f2a2c2ea000
// mprotect(0x7f2a2c2f0000, 139264, PROT_NONE) = 0
// mmap(0x7f2a2c2f0000, 106496, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6000) = 0x7f2a2c2f0000
// mmap(0x7f2a2c30a000, 28672, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x20000) = 0x7f2a2c30a000
// mmap(0x7f2a2c312000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x27000) = 0x7f2a2c312000
// mmap(0x7f2a2c314000, 5640, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f2a2c314000
// close(3)                                = 0
// openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
// read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P\237\2\0\0\0\0\0"..., 832) = 832
// pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
// pread64(3, "\4\0\0\0 \0\0\0\5\0\0\0GNU\0\2\0\0\300\4\0\0\0\3\0\0\0\0\0\0\0"..., 48, 848) = 48
// pread64(3, "\4\0\0\0\24\0\0\0\3\0\0\0GNU\0I\17\357\204\3$\f\221\2039x\324\224\323\236S"..., 68, 896) = 68
// newfstatat(3, "", {st_mode=S_IFREG|0755, st_size=2220400, ...}, AT_EMPTY_PATH) = 0
// pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
// mmap(NULL, 2264656, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f2a2c0c1000
// mprotect(0x7f2a2c0e9000, 2023424, PROT_NONE) = 0
// mmap(0x7f2a2c0e9000, 1658880, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7f2a2c0e9000
// mmap(0x7f2a2c27e000, 360448, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1bd000) = 0x7f2a2c27e000
// mmap(0x7f2a2c2d7000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x215000) = 0x7f2a2c2d7000
// mmap(0x7f2a2c2dd000, 52816, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f2a2c2dd000
// close(3)                                = 0
// openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpcre2-8.so.0", O_RDONLY|O_CLOEXEC) = 3
// read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=613064, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 615184, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f2a2c02a000
// mmap(0x7f2a2c02c000, 438272, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000) = 0x7f2a2c02c000
// mmap(0x7f2a2c097000, 163840, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6d000) = 0x7f2a2c097000
// mmap(0x7f2a2c0bf000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x94000) = 0x7f2a2c0bf000
// close(3)                                = 0
// mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f2a2c028000
// arch_prctl(ARCH_SET_FS, 0x7f2a2c028c40) = 0
// set_tid_address(0x7f2a2c028f10)         = 24388
// set_robust_list(0x7f2a2c028f20, 24)     = 0
// rseq(0x7f2a2c0295e0, 0x20, 0, 0x53053053) = 0
// mprotect(0x7f2a2c2d7000, 16384, PROT_READ) = 0
// mprotect(0x7f2a2c0bf000, 4096, PROT_READ) = 0
// mprotect(0x7f2a2c312000, 4096, PROT_READ) = 0
// mprotect(0x555a4c87c000, 4096, PROT_READ) = 0
// mprotect(0x7f2a2c362000, 8192, PROT_READ) = 0
// prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
// munmap(0x7f2a2c316000, 71363)           = 0
// statfs("/sys/fs/selinux", 0x7ffd443c2ae0) = -1 ENOENT (No such file or directory)
// statfs("/selinux", 0x7ffd443c2ae0)      = -1 ENOENT (No such file or directory)
// getrandom("\xeb\xa1\x87\xc9\x7e\xdb\x07\x9a", 8, GRND_NONBLOCK) = 8
// brk(NULL)                               = 0x555a4d217000
// brk(0x555a4d238000)                     = 0x555a4d238000
// openat(AT_FDCWD, "/proc/filesystems", O_RDONLY|O_CLOEXEC) = 3
// newfstatat(3, "", {st_mode=S_IFREG|0444, st_size=0, ...}, AT_EMPTY_PATH) = 0
// read(3, "nodev\tsysfs\nnodev\ttmpfs\nnodev\tbd"..., 1024) = 424
// read(3, "", 1024)                       = 0
// close(3)                                = 0
// access("/etc/selinux/config", F_OK)     = -1 ENOENT (No such file or directory)
// openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
// newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=5712208, ...}, AT_EMPTY_PATH) = 0
// mmap(NULL, 5712208, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f2a2bab5000
// close(3)                                = 0
// mknodat(AT_FDCWD, "my_fifo2", S_IFIFO|0666) = 0
// close(1)                                = 0
// close(2)                                = 0
// exit_group(0)                           = ?
// +++ exited with 0 +++

//mkfifo is good for creating simple fifo