#if 0

CList* clist_new_args(int argc, char **argv)
{
    if (argc < 1)
        return NULL;

    CList *list = clist_new(argc, (CDeleteFunc) free);

    for (int i = 0; i < argc; ++i)
    {
        clist_append(list, strdup(argv[i]));
    }

    return list;
}

#endif


