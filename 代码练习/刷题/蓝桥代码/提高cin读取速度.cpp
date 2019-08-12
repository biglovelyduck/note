/*
我们可以在IO之前将stdio解除绑定，这样做了之后要注意不要同时混用cout和printf之类。

在默认的情况下cin绑定的是cout，每次执行 << 操作符的时候都要调用flush，这样会增加IO负担。可以通过tie(0)（0表示NULL）来解除cin与cout的绑定，进一步加快执行效率。
*/

#include <iostream>
int main() {

    std::ios::sync_with_stdio(false);

    std::cin.tie(0);
    // IO
}
