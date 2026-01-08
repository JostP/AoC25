Vsaka rdeča ploščica predstavlja možen kot nasprotnega vogala pravokotnika. Za rešitev problema smo uporabili pristop, kjer preverimo vse možne pare rdečih ploščic, saj vsak par določa potencialni pravokotnik.

Za vsak par rdečih ploščic izračunamo širino in višino pravokotnika kot absolutno razliko x in y koordinat plus ena (ker se ploščice štejejo vključno z robom). Nato izračunamo površino pravokotnika kot produkt širine in višine.

V Part 1 preprosto izberemo največjo površino med vsemi možnimi pari rdečih ploščic.

V Part 2 dodatno preverimo, da predlagani pravokotnik ne prekriva nobenih robov oziroma povezav med rdečimi ploščicami (čeprav to preverjanje deluje predvsem za dano vhodno datoteko in je nekoliko poenostavljeno). Če pravokotnik ne prekriva nobenega roba, ga upoštevamo kot veljavnega. Na koncu izberemo največjo veljavno površino.