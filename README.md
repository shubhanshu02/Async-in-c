# Async-in-c

Asynchronised Behaviour in C using Threading

> Note: This program uses POSIX threads.

## Instruction to measure performance

The file `async.c` contains an example to implement async behaviour in C. Both synchronous and asynchronous executions are shown in this piece of code.

By default, synchronous execution is enabled. To emulate the execution of a heavy task, the program sleeps for two seconds.

### Synchronous Behaviour

1. Compile the program with POSIX thread flag.

```bash
gcc async.c -lpthread
```

2. Run the program. The order of execution of functions will be printed as the output.

```bash
./a.out
```

3. Use the `time` command to check the speed of the execution in terms of seconds.

### Asynchronous Behaviour

1. Comment the lines `95` and `96`.
2. Uncomment the lines `99` and `100`.
3. Follow the steps in the above section (Synchronous Behavior).
