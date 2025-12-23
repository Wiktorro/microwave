
size_t text2num(const char* str)
{
    if (nullptr == str || 0 == *str)
    {
        return 0;
    }

    int cnt=0 ,maxcnt =0;
    char 
    maxchar = 0, // just debug purpose var
    last = *str;
    auto iter = str +1;

    while (0 != iter)
    {
        if (*iter == last)
        {
            ++cnt;
        }
        else
        {
            if (cnt > maxcnt)
            {
                maxchar = last;
                maxcnt = cnt;
                last = *iter;
            }
            
        }
        
        
        ++str;
    }
    

    return 0;
}

//

//

//