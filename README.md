# nghttp3 for Unikraft

This is a static port of the unmodified upstream release pinned in
`Makefile.uk` and `Library.uk`. It contains no application instrumentation,
network driver, event loop or performance policy patch. The upstream MIT
license is in `COPYING`; glue uses SPDX BSD-3-Clause (`COPYING.md`).

Enable `CONFIG_LIBNGHTTP3=y` with a POSIX libc. ARM64 QEMU/KVM with
musl 1.2.3 and Unikraft staging 359307a2a4cc9c1feb22683d841650902b799e4d
is the validated combination. Other architectures/libcs are not qualified.
The private config header requires POSIX headers, endian.h and byteswap.h;
it is not exported to consumers.

The library owns protocol state; applications supply I/O, time and callbacks.
It does not require the other QUIC/HTTP/3 port or an application repository.

## Standalone upstream suite

Set UK_ROOT, MUSL_PORT and PORT to the core, musl port and this repository.
Choose new absolute OUT and CFG paths. No nghttpx workspace is required.

```sh
make -C "$UK_ROOT" A="$PORT/tests/upstream" O="$OUT" C="$CFG" \
  L="$MUSL_PORT:$PORT" UK_DEFCONFIG="$PORT/tests/upstream/defconfig" defconfig
make -C "$UK_ROOT" A="$PORT/tests/upstream" O="$OUT" C="$CFG" \
  L="$MUSL_PORT:$PORT" -j8
qemu-system-aarch64 -machine virt,gic-version=host -cpu host -accel kvm \
  -m 512M -smp 1 -display none -monitor none -serial stdio -no-reboot \
  -kernel "$OUT/upstream_qemu-arm64"
```

The wrapper disables Munit fork/buffering and runs the upstream cases with a
fixed test seed. This is test-only determinism, not a source of QUIC entropy.
Archive acquisition follows the core's normal fetch/hash rules. A clean local
output may preseed the checksum-verified source archives to avoid downloads.
