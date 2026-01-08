#include "functions.h"

using namespace std;

static vector<string>* mreza;

bool jeDostopno(size_t x, size_t y, bool brisi){
    const int maxSosedov = 4;
    const char rola = '@';
    const char prazno = '.';

    if((*mreza)[y][x] == prazno) return false;

    if((x == 0 && y == 0) ||
       (x == 0 && y == mreza->size() - 1) ||
       (x == (*mreza)[y].size() - 1 && y == 0) ||
       (x == (*mreza)[y].size() - 1 && y == mreza->size() - 1)){
        if(brisi) (*mreza)[y][x] = prazno;
        return true;
    }

    int sosedi = 0;

    if(x == 0){
        if((*mreza)[y-1][0] == rola) sosedi++;
        if((*mreza)[y+1][0] == rola) sosedi++;
        if((*mreza)[y-1][1] == rola) sosedi++;
        if((*mreza)[y][1] == rola) sosedi++;
        if((*mreza)[y+1][1] == rola) sosedi++;
    }
    else if(y == 0){
        if((*mreza)[0][x-1] == rola) sosedi++;
        if((*mreza)[0][x+1] == rola) sosedi++;
        if((*mreza)[1][x-1] == rola) sosedi++;
        if((*mreza)[1][x] == rola) sosedi++;
        if((*mreza)[1][x+1] == rola) sosedi++;
    }
    else if(x == (*mreza)[y].size() - 1){
        if((*mreza)[y-1][x] == rola) sosedi++;
        if((*mreza)[y+1][x] == rola) sosedi++;
        if((*mreza)[y-1][x-1] == rola) sosedi++;
        if((*mreza)[y][x-1] == rola) sosedi++;
        if((*mreza)[y+1][x-1] == rola) sosedi++;
    }
    else if(y == mreza->size() - 1){
        if((*mreza)[y][x-1] == rola) sosedi++;
        if((*mreza)[y][x+1] == rola) sosedi++;
        if((*mreza)[y-1][x-1] == rola) sosedi++;
        if((*mreza)[y-1][x] == rola) sosedi++;
        if((*mreza)[y-1][x+1] == rola) sosedi++;
    }
    else{
        if((*mreza)[y+1][x+1] == rola) sosedi++;
        if((*mreza)[y+1][x] == rola) sosedi++;
        if((*mreza)[y+1][x-1] == rola) sosedi++;
        if((*mreza)[y][x+1] == rola) sosedi++;
        if((*mreza)[y][x-1] == rola) sosedi++;
        if((*mreza)[y-1][x-1] == rola) sosedi++;
        if((*mreza)[y-1][x] == rola) sosedi++;
        if((*mreza)[y-1][x+1] == rola) sosedi++;
    }

    if(sosedi < maxSosedov){
        if(brisi) (*mreza)[y][x] = prazno;
        return true;
    }

    return false;
}

int prestejDostopne(const vector<string>& polje){
    mreza = const_cast<vector<string>*>(&polje);

    int stevec = 0;
    for(size_t x = 0; x < polje[0].size(); x++){
        for(size_t y = 0; y < polje.size(); y++){
            if(jeDostopno(x, y, false)){
                stevec++;
            }
        }
    }
    return stevec;
}

int odstraniInPrestej(vector<string> polje){
    mreza = &polje;
    int stevec = 0;
    bool odstranil;

    do{
        odstranil = false;
        for(size_t x = 0; x < polje[0].size(); x++){
            for(size_t y = 0; y < polje.size(); y++){
                if(jeDostopno(x, y, true)){
                    odstranil = true;
                    stevec++;
                }
            }
        }
    }while(odstranil);

    return stevec;
}
