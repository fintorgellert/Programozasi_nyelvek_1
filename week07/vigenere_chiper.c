#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0, j = 0, k = 0, d = 0;
    char c;

    // Kulcs tárolására szolgáló karaktertömb (max 127 karakter + sztring lezáró karakter)
    char kulcs[128];                    

    // A titkosítandó vagy dekódolandó szöveg tárolására szolgáló karaktertömb (max 1023 karakter + sztring lezáró karakter)
    char szoveg[1024];                  
    
    // A felhasználó választása, hogy kódolni vagy dekódolni szeretne.
    printf("[K]odolni vagy [D]ekodolni szeretnel? (K/D)\n");  

    // A felhasználó választását beolvassuk (K vagy D).
    scanf("%c", &c);  

    // Az előző scanf után maradhat egy új sor karakter, amit el kell dobni (flush).
    fgetc(stdin);  

    // Kéri a felhasználótól a kulcsot (a titkosításhoz vagy dekódoláshoz).
    printf("Kerem a kulcsot!\n");  

    // Beolvassuk a kulcsot a felhasználótól (max 127 karakter).
    fgets(kulcs, 128, stdin);  

    // Levágjuk a kulcs végét, hogy eltávolítsuk a felesleges új sor karaktert.
    kulcs[strlen(kulcs) - 1] = '\0'; 

    // Kéri a felhasználótól a titkosítandó vagy dekódolandó szöveget.
    printf("Kerem a nyilt szoveget!\n");  

    // Beolvassuk a szöveget (max 1023 karakter).
    fgets(szoveg, 1024, stdin);  

    // Levágjuk a szöveg végét, hogy eltávolítsuk az új sor karaktert.
    szoveg[strlen(szoveg) - 1] = '\0';  

    // A kulcs karaktereit nagybetűsítjük (ha kisbetűsek), hogy egységesen kezelhessük a titkosítást/dekódolást.
    for (k = 0; kulcs[k] != '\0'; k++)
    { 
        // Kisbetű -> nagybetű konvertálás

        // Ha a karakter kisbetű, akkor nagybetűvé alakítjuk.
        if (kulcs[k] >= 'a' && kulcs[k] <= 'z')  
            kulcs[k] = kulcs[k] - 32;

        // A kulcs hosszát számoljuk.
        d++;  
    }

    // Ha kódolni szeretnénk
    if (c == 'K')  
    { 
        // Itt kódolunk

        // Amíg nem érünk a szöveg végére
        while (szoveg[i] != '\0')  
        {
            // Ha a kulcs végére értünk, kezdjük újra a kulcsot.
            if (j == d)  
            {
                j = 0;
            }

            // Kisbetűs titkosítás (nyílt szöveg kisbetű, kulcs nagybetű)
            if (szoveg[i] >= 'a' && szoveg[j] <= 'z')
            { 
                // Ha a nyílt szöveg karaktere kisbetű, és a kódolásnál a kulcsot alkalmazzuk

                // Ha a karakter kódolásához nem lépjük túl az 'z'-t
                if (((szoveg[i] - 97) + (kulcs[j] - 65)) <= 25)
                {
                    // Hozzáadjuk a kulcs megfelelő értékét.
                    szoveg[i] = szoveg[i] + (kulcs[j] - 65); 
                }
                else
                {
                    // Ha túllépjük az 'z'-t, akkor az 'a' után folytatjuk.
                    szoveg[i] = szoveg[i] + (kulcs[j] - 65) - 26;  
                }
            }

            // Nagybetűs titkosítás
            if (szoveg[i] >= 'A' && szoveg[i] <= 'Z')
            { 
                // Ha a nyílt szöveg karaktere nagybetű

                // Ha nem lépjük túl az 'Z'-t
                if ((szoveg[i] - 65) + (kulcs[j] - 65) <= 25)  
                {
                    // Hozzáadjuk a kulcs megfelelő értékét.
                    szoveg[i] = szoveg[i] + (kulcs[j] - 65);  
                }
                else
                {
                    // Ha túllépjük az 'Z'-t, akkor az 'A' után folytatjuk.
                    szoveg[i] = szoveg[i] + (kulcs[j] - 65) - 26;  
                }
            }

            // Következő karakterre lépünk a szövegben.
            i++; 

            // Következő kulcs karakterre lépünk.
            j++;
        }

        // Kiírjuk a kódolt szöveget.
        printf("A kodolt szoveg: %s\n", szoveg);  
    }
    
    // Ha dekódolni szeretnénk
    else if (c == 'D') 
    { 
        // Itt dekódolunk

        // Amíg nem érünk a szöveg végére
        while (szoveg[i] != '\0') 
        {
            // Ha a kulcs végére értünk, kezdjük újra a kulcsot.
            if (j == d)  
            {
                j = 0;
            }

            // Kisbetűs dekódolás
            if (szoveg[i] >= 'a' && szoveg[j] <= 'z')
            {
                // Ha a karakter kódolása nem megy negatívba
                if ((szoveg[i] - 97) - (kulcs[j] - 65) >= 0) 
                { 
                    // A kulcsot levonjuk a titkosított karakterből.
                    szoveg[i] = szoveg[i] - (kulcs[j] - 65);  
                }
                else
                {
                    // Ha túl alacsony a karakter, az 'z' után folytatjuk.
                    szoveg[i] = szoveg[i] - (kulcs[j] - 65) + 26;  
                }
            }

            // Nagybetűs dekódolás
            if (szoveg[i] >= 'A' && szoveg[i] <= 'Z')
            { 
                // Ha a karakter kódolása nem megy negatívba
                if ((szoveg[i] - 65) - (kulcs[j] - 65) >= 0)  
                {
                    // A kulcsot levonjuk a titkosított karakterből.
                    szoveg[i] = szoveg[i] - (kulcs[j] - 65);  
                }
                else
                {
                    // Ha túl alacsony a karakter, az 'A' után folytatjuk.
                    szoveg[i] = szoveg[i] - (kulcs[j] - 65) + 26;  
                }
            }

            // Következő karakterre lépünk a szövegben.
            i++;  

            // Következő kulcs karakterre lépünk.
            j++;  
        }

        // Kiírjuk a dekódolt szöveget.
        printf("A kodolt szoveg: %s\n", szoveg); 
    }
    return 0;  // Program sikeres befejezése.
}
