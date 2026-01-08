Vsaka naprava v sistemu predstavlja vozlišče v grafu, njeni izhodi pa usmerjene povezave do naslednjih naprav. Za rešitev problema smo uporabili pristop rekurzivnega iskanja, kjer sistematično preverimo vse možne poti od začetne točke you do ciljne točke out.

Za vsako napravo preverimo vse njene izhode in se po njih pomikamo naprej, dokler ne dosežemo cilja. Ker se poti v mreži pogosto prekrivajo, smo uporabili metodo pomnjenja (memoizacija). To pomeni, da si za vsako napravo, ki smo jo že obiskali, shranimo število vseh možnih poti od nje do izhoda. Če se kasneje v iskanju spet pojavimo pri isti napravi, preprosto vrnemo že izračunano vrednost, namesto da bi ponovno preverjali isto vejevje.

V Part 1 seštejemo vse unikatne poti, ki vodijo od začetne naprave do cilja, in izpišemo skupno število.

Naredili smo samo program za Part 1.