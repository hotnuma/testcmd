

bool strisblank(const char *str);

bool strisblank(const char *str)
{
    while (*str)
    {
        if (!isspace((unsigned char) *str))
            return false;
        
        ++str;
    }
    
    return true;
}


