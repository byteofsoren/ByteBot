# 1. Introduktion till programmering.
Vi börjar med att diskutera programmering som genom att använda procedurmässiga språk.
Det betyder att vi försöker beskriva vad vi vill göra i klar språk utan komplexiteten av riktig programmera.
Efter som "alla" programmering språk är skrivna på engelska så skriver vi det på engelska.

Som första exempel så antar vi att en robot ska hämta mjölken ur kylskåpet och hälla upp ett glas mjölk.

```
get milk from fridge.
pore milk in glas.
```

Det ser ut som att det skulle fungera men vad händer om det inte finns någon mjölk.
Ska vi då fortsätta med att hälla upp mjölken trots att den inte existerar?

```
if milk exists in frige{
    get milk from fridge.
    pore milk in glas.
}
```

Nu är det så att datorer och robotar är väldigt dumma och kan bara göra det du säger åt dem att göra.
Så vi kan inte plocka ut mjölken ur kylskåpet utan att gå till kylskåpet och öppna dörren.

```
walk to fridge;
open fridge dor;
if milk exists in frige{
    get milk;
    pore milk in glas;
}
```

Nu ser du att roboten ska gå till kylskåpet och hämta mjölken, men när kom glaset fram i bilden?
Så du måste se till att roboten hämtar glaset först.

```
walk to cabinet;
get glas;
place glas on table;
walk to fridge;
open fridge dor;
if milk exists in frige{
    get milk;
    go to table;
    pore milk in glas;
}
```

Men om kabinettet inte har ett glas måste du avbryta ditt program så att roboten inte går och häller mjölk i ett glas som inte existerar.

```
walk to cabinet;
if glas not exists in cabinet{
    stop;
}
get glas;
place glas on table;
walk to fridge;
open fridge dor;
if milk exists in frige{
    get milk;
    go to table;
    pore milk in glas;
}
```

Observera att den första så kallade `if` satsen har ett så kallat stopp sats som för hindrar att program körs med felaktiga data genom att helt enkelt sluta att köra det programmet.

Nu har vi fortfarande problem med satsen `pore milk in glas` som här för generellt.
Vi ska nu introducera loop satsen som ber roboten att göra samma sak flera gånger.


```
walk to cabinet;
if glas not exists in cabinet{
    stop;
}
get glas;
place glas on table;
walk to fridge;
open fridge dor;
if milk exists in frige{
    get milk;
    go to table;
    while glas not full {
        fill glass with milk;
    }
}
```

Nu ser att mjölken fylls på till att glaset är fullt.
Men vårat program börjar bli långt så vi måste bryta upp programmet i mindre program.
Det gör vi genom att använda funktioner.
Funktioner definieras så här:

```
output type fuction_name(input variables){
    code..
    return output;
}
```

Så i vårat fall kanske vi vill bryta ut fyllningen av glaset till en separat funktion.

```
none fill_glas(liquid, glas){
    while glas not full {
        fill glas with liquid;
    }
}

walk to cabinet;
if glas not exists in cabinet{
    stop;
}
get glas;
place glas on table;
walk to fridge;
open fridge dor;
if milk exists in frige{
    get milk;
    go to table;
    fill_glas(milk, glas);
}
```

Observera att nu har vi ett funktions anrop till fyllning av en flytande substans.
Nu kan vi även anropa funktionen att fylla glaset med saft i stället för mjölk.

```
fill_glass(saft, glas);
```

Och på så sätt har vi fått en modulärt användbar kod.
Nu är det så att de flesta språk anser att all kod måste ligga i sina egna funktioner.

```
none fill_glas(liquid, glas){
    while glas not full {
        fill glas with liquid;
    }
}

int main(void){
    walk to cabinet;
    if glas not exists in cabinet{
        stop;
    }
    get glas;
    place glas on table;
    walk to fridge;
    open fridge dor;
    if milk exists in frige{
        get milk;
        go to table;
        fill_glas(milk, glas);
    }
}
```

I det språket vi ska använda för att programmera roboten "C" så heter start funktionen `main`.
Men I just Arduino fallet så har `main` bytts ut mot dessa två anrop.

```
void setup(){
    code...;
}

void loop(){
    code...;
}
```

Vi fortsätter senare.
