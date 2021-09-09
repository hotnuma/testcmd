#if 0

//pid_t childpid = fork();

//if (childpid < 0)
//{
//    perror("failed to fork.");
//    return EXIT_FAILURE;
//}

//if (childpid == 0)
//{
//    umask(0);
//    setsid();

//    if ((chdir("/")) < 0)
//    {
//        exit(EXIT_FAILURE);
//    }

//    // close out the standard file descriptors.
//    close(STDIN_FILENO);
//    close(STDOUT_FILENO);
//    close(STDERR_FILENO);

//    CList args;
//    args.append(strdup("/usr/bin/mpv"));
//    args.append(strdup("/home/hotnuma/Downloads/test.avi"));
//    args.append(nullptr);

//    char **argv = (char**) args.data();

//    if (execve(argv[0], (char**) argv, __environ) == -1)
//        perror("Could not execve");

//    for (int i = 0; i < args.size(); ++i)
//    {
//        void *ptr = argv[i];

//        if (ptr)
//            free(ptr);
//    }
//}

float get_loadavg()
{
    CString buffer(MAX_BUFF);

    FILE *fp = fopen ("/proc/loadavg", "r");

    size_t bytes_read = fread(buffer.data(), 1,
                              MAX_BUFF, fp);
    fclose (fp);

    if (bytes_read == 0)
    {
        print("read error");
        return 0;
    }

    buffer.terminate(MAX_BUFF - 1);

    //print(buffer);

    CStringList parts = buffer.split(" ");

    int size = parts.size();

    if (size < 3)
        return 0;

    print(parts.at(0));
    fflush(stdout);

//    double one = strtod(parts.at(0), nullptr);
//    double two = strtod(parts.at(1), nullptr);
//    double three = strtod(parts.at(3), nullptr);

    return 0;
}

float get_value()
{
    CString buffer(MAX_BUFF);

    FILE *fp = fopen ("/proc/stat", "r");

    size_t bytes_read = fread(buffer.data(), 1,
                              MAX_BUFF, fp);
    fclose (fp);

    if (bytes_read == 0)
    {
        print("read error");
        return 0;
    }

    buffer.terminate(MAX_BUFF - 1);

    char *start = buffer.data();

    CString result;
    fileGetLine(&start, result);

    //print(result);

    CString params = result.mid(5);

    //print(params);

    CStringList parts = params.split(" ", true);

    int size = parts.size();

    if (size < 3)
        return 0;

    double user = strtod(parts.at(0), nullptr);
    double system = strtod(parts.at(2), nullptr);
    double nprocs = get_nprocs();

    if (nprocs < 1)
        return 0;


    return 0;
}

#endif


