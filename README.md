iota-net
========

Cross platform minimal c++ networking library. Also provides extern c.

## Why?

There are several great cross platform socket libraries but they go above and beyond with several extra features which means code you may not use. All iota-net does is provide you a simple socket interface that you can listen / connect to and send/recv from. That's it.

### Things iota-net is not!
- __fault tolerant__ - Your connection goes down? It's on you to handle it.
- __channel manager__ - Your only channel is the endpoint you connect to.
- __serialiser / deserialiser__ - Your only format is undelimited bytes.
- __multi-threaded__ - You are in charge of threading ie. everything blocks.

## References

- SDL_Net
- enet

## Platforms

Works across major platforms through compiler macros. CMake will help make sure you compile for the correct platform. MSYS or Cygwin may work as well for Windows and I will try to test for this.

- *nix / OSX / BSD - Uses BSD sockets

- Windows - Requires winsock/winsock2
