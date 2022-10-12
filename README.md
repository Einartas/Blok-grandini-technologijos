
# Hash generatorius

Programa skirta suhashuoti įvairaus ilgio tekstą ar simbolių kratinį.


## Bandymas su failais

TikQ (100 simboliu)

9BDED4E9DDD1D8DAF5EBEBEFF2EE0F0D06140E181323322D1E1E193D323A3250
9BDED4E9DDD1D8DAF5EBEBEFF2EE0F0D06140E181323322D1E1E193D323A3250

TikW (100 simboliu)

9BDED4E9DDD1D8DAF5EBEBEFF2EE0F0D06140E181323322D1E1E193D323A3250
9BDED4E9DDD1D8DAF5EBEBEFF2EE0F0D06140E181323322D1E1E193D323A3250

Random1 (90000 simboliu)

FD373D32463A2135304424382D3738262F3F47233C2C3D28393732483D432B49
FD373D32463A2135304424382D3738262F3F47233C2C3D28393732483D432B49

Random2 (90000 simboliu)

FD4331463A2635293C383024212B443223333B37283849342D2B263C29371F35
FD4331463A2635293C383024212B443223333B37283849342D2B263C29371F35

TekstasA (1473 simboliai)

2647864C816A3E7343803D6E8077554486978C497B505E4E84837F9688939097
2647864C816A3E7343803D6E8077554486978C497B505E4E84837F9688939097

TekstasB (1473 simboliai)

2668676D624B5F5262615E4F5F58766567766D685C717D6D6364607567747178
2668676D624B5F5262615E4F5F58766567766D685C717D6D6364607567747178

Empty (0 simboliu)

45887E83776B72647F7575696C688977707E78726D7D8C77686863776C746C7A
45887E83776B72647F7575696C688977707E78726D7D8C77686863776C746C7A

Atlikus bandymus matoma, kad to paties teksto hash'ai visada vienodi, o skirtingų tekstų hash'ai vienodo ilgio ir skirtingi.
## Greičio matavimas su konstitucija.txt

1 eilutė:    0,000016s

2 eilutės:   0,00003s

4 eilutės:   0,00005s

8 eilutės:   0,000087s

16 eilučių:  0,00024s

32 eilutės:  0,00045s

64 eilutės:  0,0009s

128 eilutės: 0,0019s

254 eilutės: 0,0031s

512 eilučių: 0,0073s

789 eilutės: 0,0115s

Bandymai su kiekvienu skaičiumi eilučių pakartoti po 4 kartus, išvestas vidurkis.
## Bandymas su 100 000 atsitiktinai sugeneruotų eilučių po 1000 simbolių

Visi hash'ai skirtingi, t.y. 0 kolizijų.
## Bandymas su 100 000 atsitiktinai sugeneruotų eilučių porų su 1 pakeistu simboliu

Visi hash'ai skirtingi, t.y. 0 kolizijų.
## Panašumo bandymai

100 000 eilučių porų su 1 pakeistu simboliu HEX lygyje: 50.7625%

100 000 eilučių porų su 1 pakeistu simboliu BIT lygyje: 70,8375%

## Trūkumai

Hash'ų panašumas yra gana didelis, ypač bitų lygyje.

Hash'avimo greitis nėra labai geras(lyginant su SHA-256).
## Privalumai

Hash'ai visada skirtingi, nebuvo nei vienos kolizijos.
