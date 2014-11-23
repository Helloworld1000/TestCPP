/*
  main.cpp
  TestCPP

 Created by Mario Powalla on 17.12.12.
 Copyright (c) 2012 Mario Powalla. All rights reserved.

 CPP-Lernprogramm
 
 Anmerkung: Die Bezeichnungen bleiben alle in englischer Sprache (auch bei deutschen Sätzen).
 
 Stern mit Slash ist der typische multi-column C-Comment-Style - immer noch gültig und ist nicht 'VERSCHACHTELBAR'.
 
 GUTE QUELLEN:
 Jörn Löviscach auf Youtube - Mathe und C lernen
 Wikipedia
 LearnCPP.com
 
 
 C++ Referenz zur Sprache: Ausdrücke und Operatoren
 Operator                                   Bedeutung                                   Priorität / Überladbar
 Klassenname::Element                       Bereichsauflösung                           18          Nein
 Namensbereichsname::Element                Bereichsauflösung                           18          Nein
 ::Name                                     global                                      18          Nein
 ::qualifizierter-Name                      global                                      18          Nein
 
 Objekt.Element                             Elementauswahl                              17          Nein
 Zeiger->Element                            Elementauswahl                              17          Ja
 Zeiger[Ausdruck]                           Indizierung                                 17          Ja
 Ausdruck(Ausdrucksliste)                   Funktionsaufruf                             17          Ja
 Typ(Ausdrucksliste)                        Werterzeugung                               17          –
 lvalue++                                   Postinkrement                               17          Ja
 lvalue--                                   Postdekrement                               17          Ja
 typeid(Typ)                                Typidentifikation                           17          –
 typeid(Ausdruck)                           Laufzeit-Typidentifikation                  17          –
 dynamic_cast(Ausdruck)                     laufzeitgeprüfte Konvertierung              17          –
 static_cast(Ausdruck)                      compilezeitgeprüfte Konvertierung           17          –
 reinterpret_cast(Ausdruck)                 ungeprüfte Konvertierung                    17          –
 const_cast(Ausdruck)                       Konstanten Konvertierung                    17          –
 
 sizeof Objekt                              Objektgröße                                 16          –
 sizeof Typ                                 Typgröße                                    16          –
 ++lvalue                                   Präinkrement                                16          Ja
 --lvalue                                   Prädekrement                                16          Ja
 ~Ausdruck                                  bitweise Negation                           16          Ja
 !Ausdruck                                  logische Negation                           16          Ja
 -Ausdruck                                  Vorzeichen Minus                            16          Ja
 +Ausdruck                                  Vorzeichen Plus                             16          Ja
 &lvalue                                    Adresse                                     16          Ja
 *Ausdruck                                  Dereferenzierung                            16          Ja
 new Typ                                    Erzeugung (Belegung)                        16          Ja
 new Typ(Ausdrucksliste)                    Erzeugung (Belegung mit Initialisierung)	16          Ja
 new Typ[Ausdruck]                          Felderzeugung (Belegung)                    16          Ja
 new (Ausdrucksliste) Typ                   Erzeugung (Plazierung)                      16          Ja
 new (Ausdrucksliste) Typ(Ausdrucksliste)	Erzeugung (Plazierung mit Initialisierung)	16          Ja
 delete zeiger                              Zerstörung                                  16          Ja
 delete[] zeiger                            Feldzerstörung                              16          Ja
 (Typ) Ausdruck                             ungeprüfte Konvertierung                    16          –
 
 Objekt.*Zeiger-auf-Element                 Elementauswahl                              15          Nein
 Zeiger->*Zeiger-auf-Element                Elementauswahl                              15          Ja
 
 Ausdruck * Ausdruck                        Multiplikation                              14          Ja
 Ausdruck / Ausdruck                        Division                                    14          Ja
 Ausdruck % Ausdruck                        Modulo                                      14          Ja
 
 Ausdruck + Ausdruck                        Addition                                    13          Ja
 Ausdruck - Ausdruck                        Subtraktion                                 13          Ja
 
 Ausdruck << Ausdruck                       Linksschieben                               12          Ja
 Ausdruck >> Ausdruck                       Rechtsschieben                              12          Ja
 
 Ausdruck < Ausdruck                        kleiner als                                 11          Ja
 Ausdruck <= Ausdruck                       kleiner-gleich                              11          Ja
 Ausdruck > Ausdruck                        größer als                                  11          Ja
 Ausdruck >= Ausdruck                       größer-gleich                               11          Ja
 
 Ausdruck == Ausdruck                       gleich                                      10          Ja
 Ausdruck != Ausdruck                       ungleich                                    10          Ja
 
 Ausdruck & Ausdruck                        bitweise Und                                9           Ja
 
 Ausdruck ^ Ausdruck                        bitweise Exklusiv-Oder                      8           Ja
 
 Ausdruck | Ausdruck                        bitweise Oder                               7           Ja
 
 Ausdruck && Ausdruck                       logisches Und                               6           Ja
 
 Ausdruck || Ausdruck                       logisches Oder                              5           Ja
 
 Ausdruck ? Ausdruck : Ausdruck             Auswahl                                     4           Nein
 
 lvalue = Ausdruck                          Zuweisung                                   3           Ja
 lvalue *= Ausdruck                         Multiplikation und Zuweisung                3           Ja
 lvalue /= Ausdruck                         Division und Zuweisung                      3           Ja
 lvalue %= Ausdruck                         Modulo und Zuweisung                        3           Ja
 lvalue += Ausdruck                         Addition und Zuweisung                      3           Ja
 lvalue -= Ausdruck                         Subtraktion und Zuweisung                   3           Ja
 lvalue <<= Ausdruck                        Linksschieben und Zuweisung                 3           Ja
 lvalue >>= Ausdruck                        Rechtsschieben und Zuweisung                3           Ja
 lvalue &= Ausdruck                         bitweise Und und Zuweisung                  3           Ja
 lvalue |= Ausdruck                         bitweise Oder und Zuweisung                 3           Ja
 lvalue ~= Ausdruck                         bitweise Exklusiv-Oder und Zuweisung        3           Ja
 
 throw Ausdruck                             Ausnahme werfen                             2           –
 
 Ausdruck, Ausdruck                         Komma (Sequenzoperator)                     1           Ja
 
 
 
 
 
 
 
 
 
 OPERATOREN
 Modulo, modulus oder mod ist als Prozentzeichen definiert: %
 und gibt den ganzzahligen Restwert eines Bruches an
 Beispiel: 17/4 = 4 % 1

 XXX
 Zahl 1 Modulo Zahl 2 = Rest, der bei der Division entsteht.
 -->
 5 % 2 = 1
 13 % 9 = 4
 21 % 7 = 0
 
 XXX
 Modulo ist eine Division mit der Besonderheit, dass ganze Zahlen rauskommen, gegebenfalls also ein Rest bleibt.
 Als Zeichen nimmt man (zumindest in der Programmierung) %. Das heißt also z.B:
 
 5 % 2 = 2 Rest 1
 11 % 3 = 3 Rest 2
 14 % 7 = 2 Rest 0
 
 XXX
 Die zu ganzen Zahlen a, b (b>0) eindeutig bestimmten q, r aus Z heissen Quotient (auch: Ganzteil) bzw. 
 Rest der Division a:b. Für den Quotienten q schreibt man [a/b], der Rest r wird notiert: a mod b 
 (gelesen: "a modulo b").
 Beispiel: [-17/5] = -4 und (-17) mod 5 = 3. Aber: -17 mod 5 = -2 (mod bindet stärker als -, +, *, /)
 
 XXX
 Das "zeichen das so ähnlich aussieht wie =" bedeutet kongruenz. Ich schreib das kongruenz-zeichen mal als = weil 
 ich mich jetzt nicht mit sonderzeichen beschäftigen will. Kongruenzzeichen ist ein Gleichheitszeichen mit drei Strichen.
 
 Wenn du z.B. so eine Gleichung hast:
 
 5 = x mod 3
 
 Was bedeutet das?
 Das bedeutet, das hier alle zahlen x gefragt sind, die kongruent zu 5 modulo 3 sind. 
 Das wiederum bedeutet, dass der rest aus den beiden ganzzahligen divisionen (5/3) und (x/3) gleich sein muss,
 damit diese Gleichung erfüllt ist.
 
 Das Ergebnis von 5/3 = 1. rest bleibt über, nämlich 2.
 Also für x=5 ist die gleichung logischerweise erfüllt.
 Jetzt musst du alle x finden, für die der rest aus der division durch 3 ebenfalls 2 ist. dann gelten die zahlen 5 und x als kongruent.
 
 lösung also: x = 2, 5, 8, 11, 14, 17, ......

 XXX
 also angenommen hier ist die gleichung:
 
 a = b mod m
 
 das bedeutet, dass a/m und b/m den gleichen rest haben.
 
 das kann man nun auch so schreiben:
 
 a = b + q*m für alle q = 0,1,2,3,....
 
 damit hast du eine gleichung mit 2 unbekannten (q und entw. a oder b) und somit unendlich viele lösungen.
 
 zb a = 3x
 b = 9
 m = 12
 
 3x = 9 mod 12 (hier meine ich das kongruenz-zeichen)
 
 bedeutet:
 a = b + q*m
 3x = 9 + q*12
 
 nun schreibe für alle q>=0 alle ergebnisse für x auf:
 q | x
 --------
 0 | 3
 1 | 7
 2 | 11
 3 | 15 => mod 12 = 3
 4 | 19 => mod 12 = 7
 ....
 
 man erkennt hier ein system.
 es gibt also 3 "restklassen", nämlich 3, 7 und 11.

 XXX
 Modulo Einsatzgebiete:
 - Elektronik - für Schaltlogik
 - Brüche spät in eine Gleitkommazahl zu verwandeln ist bei Binärsystemen eine gute Idee (kein analoges Handling von
 periodischen Zahlen).
 - Analog Uhr & Uhrenberechnung - Schema für Wertbehandlung über Divisor (12 oder 24 - bzw. Kalender 31/30/29/28/365)
 - Luhn-Algorithmus (Prüfung von Kreditkarten-Nummern - gemeinfreier Algorithmus)
 
 
 *****VOID*****
http://www.youtube.com/watch?v=BPUkE095oqc 
 
*/
// Double-Slash ist ein Single-Line-Comment.

//
// Die Function main() ist immer Grundgerüst eines CPP-Programms.
//
// Eine Function ist eine Gruppe von Statements.
// Statements 
// ; (Semikolon) ist stets das Ende eines Statements - Statement wird terminated.
//
//
// Libraries sind vorgefertigte Sammlungen von Functions die über einen Linker eingebunden werden.
//
//
//
// <iostream> ist eine Preprocessor Directive (im Deutschen: Präprozessor Direktive)
// std steht für Standard und ist Bestandteil von <iostream>
// cout und endl sind Bestandteil von <iostream> std
// << ist ein Operator - vergleichbar mit + (dem Pluszeichen)
//
//  using namespace
//
//  return 0 - bestätigt das ordnungsgemäße Programmende
//
// Statements sind Feststellungen (als Assignment Statement: x = 7 oder oder als Declaration Statement: int x)
//
// Expressions sind Ausdrücke (Rechenaufgaben: 2-1, 3+1, x-1, y*z)
// A statement is a “complete sentence” that tells the compiler to perform a particular task. An expression is a mathematical entity that evaluates to a value. Expressions are often used inside of statements.
//

//Taschenrechner

#include <iostream>
#include <cstdlib>
using namespace std;

void addition ()
{
    int Zahl1, Zahl2;
    cout << "Sie haben sich für die Addition entschieden" << endl;
    cout << "1. Zahl: ";
    cin >> Zahl1;
    cout << "2. Zahl: ";
    cin >> Zahl2;;
    cout << "Das Ergebnnis lautet: " << (Zahl1 + Zahl2) << endl;    
}

void subtraktion ()
{
    int Zahl1, Zahl2;
    cout << "Sie haben sich für die Subtraktion entschieden" << endl;
    cout << "1. Zahl: ";
    cin >> Zahl1;
    cout << "2. Zahl: ";
    cin >> Zahl2;;
    cout << "Das Ergebnnis lautet: " << (Zahl1 - Zahl2) << endl;    
}

int main()
{
    int decide;
    
    cout << "Taschenrechner" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Substraktion" << endl;
    cin >> decide;
    if (decide == 1) addition ();
    if (decide == 2) subtraktion ();

    return 0;
}
