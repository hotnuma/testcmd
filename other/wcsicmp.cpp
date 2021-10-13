#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include "print.h"
#include "CList.h"

struct Entry
{
    wchar_t *str = nullptr;
    wchar_t *sortkey = nullptr;
};

Entry* entryNew(const wchar_t *str)
{
    Entry *entry = new Entry;

    entry->str = _wcsdup(str);

    int len = wcsxfrm(nullptr, str, 0);
    wchar_t *key = (wchar_t*) malloc((len+1) * sizeof(wchar_t));
    wcsxfrm(key, str, len+1);

    entry->sortkey = key;

    //printf("len = %i\n", len);

    return entry;
}

void entryDelete(Entry *entry)
{
    if (!entry)
        return;

    if (entry->str)
        free(entry->str);

    if (entry->sortkey)
        free(entry->sortkey);

    delete entry;
}

int compare(const void *e1, const void *e2)
{
    Entry *entry1 = *(Entry**) e1;
    Entry *entry2 = *(Entry**) e2;

    return wcsicmp(entry1->sortkey, entry2->sortkey);
//    return wcsicmp(entry1->str, entry2->str);
}

int main(int argc, char *argv[])
{
    print(setlocale(LC_COLLATE, "fr-FR"));

    CList list;
    list.setDeleteFunc((CListDeleteFunc) entryDelete);

    list.append(entryNew(L"é"));
    list.append(entryNew(L"f"));
    list.append(entryNew(L"e"));
    list.append(entryNew(L"E"));
    list.append(entryNew(L"d"));
    list.append(entryNew(L"è"));

    list.sort(compare);

    int size = list.size();

    for (int i = 0; i < size; ++i)
        printf("%ls\n", ((Entry*) list[i])->str);

    return 0;
}


