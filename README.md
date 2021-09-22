# CVE-2018-6574

Remote command execution in `Golang` go get command.

CVE-2018-6574 this vulnerability impacts Golang go get command and allows an attacker to gain code execution on a system by installing his malicious library, this vulnerability was fixed in Go 1.8.7, 1.9.4 and 1.10rc2.

Golang will build native extensions. This can be used to pass additional flags to the compiler to gain code execution. For example, `CFLAGS` can be used.
