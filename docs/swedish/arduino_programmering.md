# Arduino programmering
Nu ska vi kicka av programmeringen av Arduino kortet men innan vi går till att programmera roboten måste vi lära oss lite om hur man programmerar enklare saker än en robot.
Som standard börjar man blinka med lys dioden på kortet.

![bytebot led on off](../uml/led_onoff.png "Tänd och släck lysdiod")

I illustrationen av programmet ovan ser du att en lysdiod tänd, vänta, släck och slutligen vänta igen.
Sedan startas programmet om från början igen med tänd, vänta, släck och vänta.

Fråga varför behöver vi den sista vänta?
Svar: Efter som när programmet går runt och börjar om från början så kommer tiden lampan är släkt att vara noll.
Detta med för att lysdioden aldrig kommer vara avstängd.


Så hur skriver vi det i Arduino miljön?
Först frågar vi os vad som är meningen med programmet.
Vart jag svarar att blinka en lampa på och av en gång i sekunden.
Så här löste jag det.
(Jag förklarar hur programmet fungerar under kod stycket).

``` c
void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
}
void loop(){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}
```

Vi kan börja med att observera att det är två funktioner i programmet.
Det vi börjar med är det som står i `loop()` funktionen så tar vi `setup()` funktionen senare.

1. `digitalWrite()` är ett funktions anrop som vill ha två parametrar.
    1. `LED_BUILTIN` talar om för programmet att den inbyggda lysdioden ska användas.
    2. `HIGH` eller `LOW` talar om lysdioden att den ska vara på eller av.

Det vill säga att den första `digitalWrite(LED_BUILTIN, HIGH)` talar om för systemet att lampan ska tändas.

2. `delay()` med endast ett nummer för fördröjning i millisekunder.
Så exempelvis `delay(1000)` är lika med en fördröjning på en sekund.

3. Det `setup()` funktionen gör i det här fallet är att förbereda programmet för vilka funktioner vi vill använda på Arduino kortet.
I detta fall så har vi `pinMode(LED_BUILTIN, OUTPUT);` som förbereder `LED_BUILTIN` för att vara en ut signal från Arduinot.
Men oroa dig inte om du inte förstår den här raden just nu, vi återkommer till den senare.


Så prova att ändra I programmet så att ni kan ha lampan tänd längre och kortare eller kan ni göra sekvenser av på/av?

# SOS
SOS är ett meddelande som skickas av fartyg, flygplan och andra större farkoster när de befinner sig i knipa.
Det meddelandet skickades vanligen med morse koder fram tills typ 90talet men förekommer fortfarande.
För att skicka ett SOS meddelande med en telegraf var man tvungen att "knacka" in sitt meddelande på en tangent och det gick till så här:

För att bilda ett s med telegrafen så slår man tre korta slag `...`
För att bilda ett o med telegrafen så slår man tre långa slag `---`.
Därmed för att skriva SOS med telegrafen så slog man `...---...`.

Om vi antar att skillnaden på korta och långa slag är tiden som lampan är påslagen.
Hur skulle du modifiera koden ovan för att skapa SOS meddelandet?
Fundera och testa ett tag innan du läser vidare.

# Potentiell lösning till SOS


``` c
void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
}
void loop(){
    // S ...
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);

    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);

    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);

    // O ---
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);

    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);

    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);

    // S ...
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);

    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);

    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
}
```

Det fungerar men om du frågar mig så tycker jag att det är ganska klonkigt med massor av repetitioner.
Hur kunde vi förbättra det, kan vi möjligen skriva två funktioner som gör det enklare?
Fundera och prova innan du går vidare.


# Funktioner
Jag har tidigare pratat om funktioner men nu är det dags att vi skriver våra egna.
Börja med att skapa ett nytt projekt i Arduino miljön och skriv in det här först.

``` c
void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
}
void loop(){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}
```

Nu ska vi skapa två nya funktioner som heter `longLED` och `shortLED`.

``` c

void longLED(){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);

}
void shortLED(){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
}

void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
}
void loop(){
    // S ...
    shortLED();
    shortLED();
    shortLED();
    // O ---
    longLED();
    longLED();
    longLED();
    // S ...
    shortLED();
    shortLED();
    shortLED();
}
```
Alla funktioner som du skriver måste stå ovanför `setup()` och `loop()` för att programmet ska fungera.
Det finns sätt att komma runt detta, men det tar vi eventuellt senare om det behövs.




