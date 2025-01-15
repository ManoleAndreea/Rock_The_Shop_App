ROCK the SHOP
Sistem pentru administrarea unui magazin
I. Descriere
Un magazin online cu produse rock pune la vânzare mai multe categorii de produse și se
ocupă cu primirea, procesarea și livrarea comenzilor. Angajații magazinului au responsabilități
distincte: managerul se ocupă de managementul stocului de produse, operatorii de comenzi
se ocupă cu căutarea de produse în stoc, ambalarea și livrarea acestora, iar asistenții dau o
mână de ajutor în ce privește monitorizarea comenzilor.
Magazinul are 3 tipuri de angajați (manager, operator comenzi și asistent). Toți au ID, nume,
prenume, CNP, data angajării. ID-ul este unic, asignat la angajare și nu se modifică pe perioada
angajării. Pentru orice angajat CNP-ul trebuie să fie unul valid* și numele și prenumele să aibă
minim 3 caractere, dar nu mai mult de 30.
Salariul fiecărui angajat se calculează pornind de la un salariu de baza (3500 RON) la care
se adaugă 100 RON pentru fiecare an de vechime. La final se aplică un coeficient de salariu în
funcție de tipul angajatului: coeficientul este 1.25 pentru manager, 1 pentru operator comenzi
și 0.75 pentru asistent. Operatorii de comenzi primesc bonus 0.5% din valoare comenzilor pe
care le procesează (valoarea comenzilor include costuri de împachetare și livrare). În afară de
manager, fiecare angajat, de ziua lui, primește bonus de 100 RON care se adaugă la salariul
din acea lună.
Există posibilitatea ca, de-a lungul timpului să se facă angajări. O persoana poate să fie
angajată dacă la data angajării are cel puțin 18 ani. Trebuie să existe posibilitatea modificării
numelui unei persoane (eg. s-a căsătorit). Există posibilitatea ca un angajat să vrea să își dea
demisia, deci va trebui să dispară din evidența magazinului. Oricând este solicitat, trebuie să
fie posibilă afișarea datelor unui angajat și a salariului acestuia în luna curentă.
Magazinul vinde 3 tipuri de produse: articole vestimentare, discuri (cd-uri si viniluri) și
discuri vintage. Pentru produse se cunoaște denumirea, numărul de produse de acel tip din
stoc și prețul de bază (fără elemente ce țin de împachetare sau livrare). Toate produsele au un
cod unic care le este asignat prima dată când sunt adaugate în stoc. Pentru articolele
vestimentare se cunoaște culoarea și marca. Discurile pot să fie CD-uri sau viniluri, sunt
cunoscute: casa de discuri, data când au fost puse în vânzare, trupa și numele albumului.
Discurile vintage pot sau nu să fie mint (utilizate dar, în stare foarte bună) și au un anumit
coeficient de raritate (între 1 și 5).
_______________________________________________________________________________________
*Vezi secțiunea Validare de aici:
https://ro.wikipedia.org/wiki/Cod_numeric_personal_(Rom%C3%A2nia)
Prețul pentru fiecare tip de produs livrat e calculat adunând la prețul de bază:
- pentru articole vestimentare suma de 20 RON pentru împachetare și livrare
- pentru discuri se percepe un cost standard de livrare de 5 RON
- pentru discuri vintage prețul este calculat ca pentru discuri la care se adaugă
15 RON*coeficientul de raritate.
Oricând trebuie să existe posibilitatea de a adăuga produse noi în stoc, șterge produse din
stoc (eg. nu mai sunt fabricate), modificare număr de produse de un anumit tip din stoc (în
funcție de codul unic). Oricând este solicitat trebuie să fie posibilă afișarea datelor unui
produs și a prețului de bază și, respectiv, prețul care include costuri de împachetare și livrare.
Comenzile din partea cumparatorilor pot să conțină maxim 5 discuri și maximum 3 articole
vestimentare care se găsesc în stoc. Comanda trebuie să aibă valoare minimă (fără costuri de
împachetare sau livrare) de 100 RON. Dacă o comandă nu respectă aceste cerințe, nu va fi
procesată. Pentru fiecare comandă se reține data (momentul de timp) când a fost primită de
la cumparator și are asociată o anumită durată de soluționare (împachetare și livrare). Durata
este dată în unități de timp alese de voi.
O comandă, dacă poate să fie procesată, trebuie asignată unui operator de comenzi.
Comenzile sunt asignate în mod automat (nu manual).
Un operator nu poate să gestioneze mai mult de 3 comenzi în paralel.
Dacă la un moment dat nu se pot asigna comenzi niciunui operator, se afișează un mesaj și
comenzile vor fi plasate în așteptare până la eliberarea unui angajat.
De-a lungul timpului, operatorii trebuie să aibă relativ aceeași încărcare.
 II. Funcționalități minimale
Magazinul trebuie să poată să fie administrat din următoarele puncte de vedere:
1. - adăugare, ștergere, modificare, afișare date angajat, afișarea tuturor angajaților
Dacă magazinul nu are: un manager, minim 3 operatori de comenzi, și un asistent, nu poate
functiona și se afișează un mesaj în acest sens.
2. - adăugare, ștergere, modificare, afișare date produs, afișarea tuturor produselor din stoc
Dacă magazinul nu are în stoc măcar 2 produse din fiecare tip nu poate funcționa și se
afișează un mesaj în acest sens.
3. - procesare de comenzi (asignarea lor automată către operatorii de comenzi) și simularea
încărcării fiecărui angajat cu cereri.
4. - raportări:
- angajatul cu cele mai multe comenzi procesate
- top 3 angajați care au gestionat cele mai valoroase comenzi (în valoare sunt incluse
costurile de impachetare și livrare) – ordonați descrescător in funcție de valoarea comenzii
- top 3 angajați cu cel mai mare salariu în luna curentă – ordonați in funcție de nume si
prenume.
Indicații:
Pentru a realiza partea de management a magazinului folosiți un meniu din care utilizatorul
alege ce acțiune dorește sa facă: gestiune angajați, gestiune stoc, procesare comenzi,
raportare.
Pentru gestiunea angajaților și stocului trebuie să existe opțiuni de adăugare, ștergere,
modificare, afișare angajat/ produs, respectiv, afișarea tuturor angajaților /produselor din
stoc. Dați mesaje când o operație nu poate să fie realizată și precizați care e cauza problemei.
Pentru procesarea comenzilor trebuie să se poată observa modul în care fiecare comandă
cu detaliile specifice (id, data, durata, valoare) e asignată unui angajat și când comanda a fost
finalizată, respectiv, să se afișeze un mesaj de eroare dacă comanda nu poate să fie procesată
(ex. nu mai există produs de un anumit tip în stoc, valoarea sau numărul de produse nu
respectă cerințele, etc). Observație: Pentru transparență puteți afișa, la fiecare moment de
timp, ce face fiecare operator (ce comandă procesează).
Pentru raportare trebuie să se genereze fișiere (ideal .csv) pentru fiecare raport solicitat în
parte.
Alte observații:
- Pentru a vă popula inițial magazinul cu angajați și produse puteți să creați obiecte cu
valori alese de voi, vor fi citite date de la tastatură doar pentru a testa adăugarea unui
angajat/produs sau alte teste specifice.
- Pentru procesarea de comenzi creați un fișier care să conțină un număr suficient de
comenzi și care să permită verificarea tuturor cazurile limită care pot să apară (ex. toți angajații
sunt ocupați, comanda nu poate fi procesată, etc)
Folosiți biblioteci existente pentru data/ora.
Folosiți cât mai multe elemente de Modern C++!
Folosiți clasa string în loc de char* sau char[].

III. Punctare
- Gestiune angajați – 30 p
- Gestiune stoc – 30 p
- Procesare cereri – 30 p
- Raportare – 10p (se obține punctajul doar dacă simularea pentru procesarea de cereri
funcționează)
10% din punctaj se acordă pe calitatea documentației tehnice de maxim 4 pagini (ce explică
succint clasele folosite, modul de funcționare al aplicației, elemente tehnice de care v-ați lovit
și nu vă fuseseră predate, respectiv, descrierea testelor făcute), prezentarea aplicației și
răspunsurile la întrebările pe care vi le voi pune. Prezentarea o să fie de aprox. 7 min/pers așa
că organizați-vă cât mai eficient datele pentru teste.
Folosiți clasa string, fișiere și, pentru partea de procesare de cereri (și nu numai), cât mai
multe elemente de Modern C++ (STL, lambda, etc - vezi C11 si C12).
Punctajul integral se obține DOAR DACĂ:
- toate corner cazurile limită sunt testate și aceasta se poate observa în prezentarea pe care
o faceți
- sunt folosite structuri de date (STL) adecvate fiecărei situații
- maniera de organizare și scriere a codului este una ordonată și lizibilă, fiecare clasa e
implementată in fișiere distincte.
- sunt utilizate cât mai multe elemente de Modern C++ (acolo unde are sens).
IV. Deadline și detalii legate de încărcarea și prezentarea proiectului
Deadline hard: 12.01.2025 23:59
Bonus: +5% din punctajul obținut, dacă proiectul e încărcat în forma finală înainte de
01.01.2025.
Se încarcă pe Moodle doar fișierele .h și .cpp, fisierele cu date de test și un fișier
(Popescu_Ion_321_a.pdf) pentru documentație, care trebuie să fie cât mai concisă. Orice
proiect care nu respectă cerințele de încărcare nu va fi evaluat.
În saptămâna 14, fiecare student, la semigrupa de care aparține, va prezenta proiectul (ideal
de pe laptopul personal) – 7 min/prezentare.
Proiectele o sa fie testate pentru similitudini folosind Moss. Temele cu similitudini o să fie
punctate cu -10p din nota finală (atât tema „sursă” cât și tema „destinație”).
