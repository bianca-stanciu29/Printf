Stanciu Bianca-Andreea, 325CC
________________________________________________________________________________________________________________________

Pornind de la functia data, write_stdout, in functia iocla_printf am evaluat fiecare caz in functie de specificatori.
Am initializat argumentele si cu va_start am aflat de unde încep argumentele variabilelor, parcurgand
caracter cu caracter textul primit ca argument. Deoarece fiecare specificatie este inclusa prin caracterul "%", am
testat daca caracterul este egal cu % si in functie de urmatorul argument am construit un sir de caractere care urmeaza
sa fie afisat.
________________________________________________________________________________________________________________________

Specificatorul %d: -am retinut intr-o variabila booleana daca numarul este negativ. Pentru a putea folosi functia
write_stdout am convertit numarul intr-un sir de caractere.Pentru a pune fiecare cifra a numarului in sirul de caractere
am aplicat modul pentru a evita aparitia repetata a semnului minus la fiecare extragere. Daca numarul este negativ,
primul caracter din result va fi semnul minus "-", iar apoi parcurgand sirul de caractere construit anterior de
la coada la cap, voi adauga in result cifra cu cifra.
________________________________________________________________________________________________________________________

Specificatorul %u: -Am construit asemanator sirul de caractere cu cifrele numarului, iar in acest caz nu am mai folosit
functia modul pentru ca nu se mai tine cont de semn.
Parcurgand sirul de caractere construit anterior de la coada la cap, voi adauga in result cifra cu cifra.
________________________________________________________________________________________________________________________

Specificatorul %c: -Deoarece este un singur caracter, in sirul result_string am adaugat caracterul.
________________________________________________________________________________________________________________________

Specificatorul %s: - Am parcurs sirul de caractere si in sirul result_string am adaugat caracter cu caracter.
________________________________________________________________________________________________________________________

Specificatorul %%: -daca urmatorul caracter dupa % este tot % atunci in result_string voi adauga caracterul %;
________________________________________________________________________________________________________________________

Specificatorul %x: -pentru aceasta transformare am cautat si pe internet.
Pentru a transforma in hexazecimal am initializat un string cu multimea valorilor hexazecimale
si am testat cat timp numarul mai are cifre,iar in variabilaremainder voi retine restul impartirii la 16. In functie de
acel rest voi adauga in stringul hex_string valoarea corespunzatoare din sirul de valori hexazecimale. La final am pus
in ordine inversa in sirul result_string sirul obtinuthex_string.
________________________________________________________________________________________________________________________
Daca dupa specificatorul % nu mai este niciun caracter corespunzator, in sirul result_string voi adauga caracterul
respectiv, la final adaugand caracterul terminal. Dupa parcurgerea intregului format, voi apela functia write_stdout
pentru a afisa rezultatul final.
