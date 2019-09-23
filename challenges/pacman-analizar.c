    //My pacman analizer A01227885


    //here we include all the libraries we are going to need
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    #include <fcntl.h>

    #include <unistd.h>

    #include <string.h>

    #include <sys/types.h>
    #include <sys/stat.h>


    //we define all the variables
    //status
    #define installed 0
    #define removed 1
    #define upgraded 2

    //actions
    #define date 10
    #define find 11
    #define fetch 12
    #define fetch_name 13
    #define find_lane 14

    //we are going to get the following file for the report
    #define report_file "packages_report.txt"


    //we define a package to move things together
    struct Package
    {
        char nam[50];
        char dat[17];
        char upt[17];
        int upd;
        char rdt[17];
        int stat;
    };


    //we defne our hashtable with an array of 1000
    struct Hashtable
    {
        int size;
        int nelements;
        struct Package array[1000];
    };


    //here we initialize the functions
    void analize(char *logFile, char *report);
    bool action(char c1, char c2);
    void addinghash(struct Hashtable *ht, struct Package *p);
    int hashcode(char s[]);
    bool findhash(struct Hashtable *ht, char key[]);
    struct Package *get(struct Hashtable *ht, char key[]);
    void printhash(struct Hashtable *ht);
    void newtostring(char string[], struct Hashtable *ht);
    void printpck(struct Package *p);
    void stringpck(char string[], struct Package *ht);
    void mkerep(char *reportS, int iPackages, int rPackages, int uPackages, int cInstalled, struct Hashtable *ht);


    //our main function
    int main(int argc, char **argv)
    {

        if (argc < 2)
        {
            printf("Usage:./pacman-analizer.o pacman.txt\n");
            return 1;
        }

        analize(argv[1], report_file);

        return 0;
    }

    //here we start to define all of our functions
    void analize(char *logFile, char *report)
    {
        printf("Generating Report from: [%s] log file\n", logFile);

        struct Hashtable ht = {1000, 0};
        int iPackages = 0;
        int rPackages = 0;
        int uPackages = 0;
        int cInstalled = 0;

        int fd = open(logFile, O_RDONLY);
        if (fd == -1)
        {
            printf("Failed to open the file.\n");
            return;
        }
        int size = lseek(fd, sizeof(char), SEEK_END);
        close(fd);
        fd = open(logFile, O_RDONLY);
        if (fd == -1)
        {
            printf("Failed to open the file.\n");
            return;
        }
        char buf[size];
        read(fd, buf, size);
        close(fd);
        buf[size - 1] = '\0';

        int i = 0;
        int j = 0;
        int state = date;
        char date[17];
        char nam[50];
        char action[10];
        bool validLine = false;
        while (i < size)
        {
            switch (state)
            {
            case date:
                if (buf[i] != 'f')
                {
                    i++;
                    j = 0;
                    while (buf[i] != ']')
                    {
                        date[j] = buf[i];
                        j++;
                        i++;
                    }
                    date[j] = '\0';
                    i = i + 2;
                    state = find;
                }
                else
                {
                    state = find;
                }
                break;

            case find:
                while (buf[i] != ' ')
                {
                    i++;
                }
                i++;
                state = fetch;
                break;

            case fetch:
                j = 0;
                if (action(buf[i], buf[i + 1]))
                {
                    validLine = true;
                    while (buf[i] != ' ')
                    {
                        action[j] = buf[i];
                        i++;
                        j++;
                    }
                    action[j] = '\0';
                    i++;
                    state = fetch_name;
                }
                else
                {
                    state = find_lane;
                }
                break;

            case fetch_name:
                j = 0;
                while (buf[i] != ' ')
                {
                    nam[j] = buf[i];
                    i++;
                    j++;
                }
                nam[j] = '\0';
                i++;
                state = find_lane;
                break;

            case find_lane:
                while (!(buf[i] == '\n' || buf[i] == '\0'))
                {
                    i++;
                }
                i++;
                if (validLine)
                {
                    if (!findhash(&ht, nam))
                    {
                        struct Package p = {"", "", "", 0, "-", installed};
                        strcpy(p.nam, nam);
                        strcpy(p.dat, date);
                        addinghash(&ht, &p);

                        iPackages++;
                    }
                    else
                    {
                        struct Package *p1 = get(&ht, nam);
                        if (strcmp(action, "installed") == 0)
                        {
                            if (p1->stat == removed)
                            {
                                p1->stat = installed;
                                strcpy(p1->rdt, "-");
                                rPackages--;
                            }
                        }
                        else if (strcmp(action, "removed") == 0)
                        {
                            if (p1->stat == installed || p1->stat == upgraded)
                            {
                                p1->stat = removed;
                                strcpy(p1->rdt, date);
                                strcpy(p1->upt, date);
                                p1->upd = p1->upd + 1;
                                rPackages++;
                            }
                        }
                        else if (strcmp(action, "upgraded") == 0)
                        {
                            if (p1->stat == installed)
                            {
                                p1->stat = upgraded;
                                strcpy(p1->upt, date);
                                p1->upd = p1->upd + 1;
                                uPackages++;
                            }
                            else if (p1->stat == upgraded)
                            {
                                strcpy(p1->upt, date);
                                p1->upd = p1->upd + 1;
                            }
                        }
                    }
                }
                validLine = false;
                state = date;
                if (i >= size - 1)
                {
                    i = i + 1;
                }
                break;
            }
        }
        cInstalled = iPackages - rPackages;
        char reportS[100000];
        mkerep(reportS, iPackages, rPackages, uPackages, cInstalled, &ht);
        fd = open(report, O_CREAT | O_WRONLY, 0600);
        if (fd == -1)
        {
            printf("Failed to open the file.\n");
            return;
        }
        write(fd, reportS, strlen(reportS));
        close(fd);

        printf("Report is generated at: [%s]\n", report);
    }

    bool action(char c1, char c2)
    {
        if (c1 == 'i' || c1 == 'u')
        {
            return true;
        }
        else if (c1 == 'r' && c2 == 'e')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void addinghash(struct Hashtable *ht, struct Package *p)
    {
        for (int i = 0; i < ht->nelements + 1; i++)
        {
            int hashValue = hashcode(p->nam) + i;
            int index = hashValue % ht->size;
            if (strcmp(ht->array[index].nam, "") == 0)
            {
                ht->array[index] = *p;
                break;
            }
        }
        ht->nelements += 1;
    }

    int hashcode(char s[])
    {
        int n = strlen(s);
        int hashValue = 0;

        for (int i = 0; i < n; i++)
        {
            hashValue = hashValue * 31 + s[i];
        }

        hashValue = hashValue & 0x7fffffff;
        return hashValue;
    }

    bool findhash(struct Hashtable *ht, char key[])
    {
        for (int i = 0; i < ht->nelements + 1; i++)
        {
            int hashValue = hashcode(key) + i;
            int index = hashValue % ht->size;
            if (strcmp(ht->array[index].nam, key) == 0)
            {
                return true;
            }
            else if (strcmp(ht->array[index].nam, "") == 0)
            {
                return false;
            }
        }
        return false;
    }

    struct Package *get(struct Hashtable *ht, char key[])
    {
        for (int i = 0; i < ht->nelements + 1; i++)
        {
            int hashValue = hashcode(key) + i;
            int index = hashValue % ht->size;
            if (strcmp(ht->array[index].nam, key) == 0)
            {
                return &ht->array[index];
            }
            else if (strcmp(ht->array[index].nam, "") == 0)
            {
                return NULL;
            }
        }
        return NULL;
    }

    void printhash(struct Hashtable *ht)
    {
        printf("ht.size: %d\n", ht->size);
        printf("ht.nelements: %d\n", ht->nelements);
        printf("ht.array: \n");
        for (int i = 0; i < ht->size; i++)
        {
            if (strcmp(ht->array[i].nam, "") != 0)
            {
                printpck(&ht->array[i]);
                printf("\n");
            }
        }
    }

    void newtostring(char string[], struct Hashtable *ht)
    {
        for (int i = 0; i < ht->size; i++)
        {
            if (strcmp(ht->array[i].nam, "") != 0)
            {
                stringpck(string, &ht->array[i]);
                strcat(string, "\n\n");
            }
        }
    }

    void printpck(struct Package *p)
    {
        printf("- Package name        : %s\n", p->nam);
        printf("  - Install date      : %s\n", p->dat);
        printf("  - Last update date  : %s\n", p->upt);
        printf("  - How many update  : %d\n", p->upd);
        printf("  - Removal date      : %s\n", p->rdt);
    }

    void stringpck(char string[], struct Package *p)
    {
        strcat(string, "- Package name        : ");
        strcat(string, p->nam);
        strcat(string, "\n");
        strcat(string, "  - Install date      : ");
        strcat(string, p->dat);
        strcat(string, "\n");
        strcat(string, "  - Last update date  : ");
        strcat(string, p->upt);
        strcat(string, "\n");
        strcat(string, "  - How many updates  : ");
        char numBuf[20];
        sprintf(numBuf, "%d\n", p->upd);
        strcat(string, numBuf);
        strcat(string, "  - Removal date      : ");
        strcat(string, p->rdt);
    }

    void mkerep(char *reportS, int iPackages, int rPackages, int uPackages, int cInstalled, struct Hashtable *ht)
    {
        strcat(reportS, "Pacman Packages Report\n");
        strcat(reportS, "----------------------\n");
        char numBuf[120];
        sprintf(numBuf, "- Installed packages : %d\n- Removed packages   : %d\n- Upgraded packages  : %d\n- Current installed  : %d\n\n", iPackages, rPackages, uPackages, cInstalled);
        strcat(reportS, numBuf);
        newtostring(reportS, ht);
    }
