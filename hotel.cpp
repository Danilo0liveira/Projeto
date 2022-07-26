#include "hotel.h"

bool Hotel::addQuarto(Quarto q){
    for(unsigned u = 0; u < lista_quarto.size(); u++)
            if(q.getNumero() == lista_quarto[u].getNumero)
                return false;

    if(contador == maxQuartos){
        return false;
    }

    else{
        if(q.getAndar() > getAndares() || q.getAndar() < getAndares())
            return false;

        else{
            lista_quartos.emplace_back(q);

            contador++;

            return true;
        }
    }
}

bool Hotel::addPremium(QuartoPremium q){
    for(unsigned u = 0; u < lista_premium.size(); u++)
            if(q.getNumero() == lista_premium[u].getNumero)
                return false;

    if(contador == maxQuartos){
        return false;
    }

    else{
        if(q.getAndar() > getAndares() || q.getAndar() < getAndares())
            return false;

        else{
            lista_premium.emplace_back(q);

            contador++;

            return true;
        }
    }
}

bool Hotel::addPcD(QuartoPcD q){
    for(unsigned u = 0; u < lista_PcD.size(); u++)
            if(q.getNumero() == lista_PcD[u].getNumero)
                return false;

    if(contador == maxQuartos){
        return false;
    }

    else{
        if(q.getAndar() > getAndares() || q.getAndar() < getAndares())
            return false;

        else{
            lista_PcD.emplace_back(q);

            contador++;

            return true;
        }
    }
}

bool Hotel::addReserva(Reserva r){
    for(unsigned u = 0; u < lista_reservas.size(); u++)
            if(r.getNum_Pedido()) == lista_reservas[u].getNum_Pedido())
                return false;

    for(unsigned u = 0; u < lista_reservas.size(); u++)
            if(r.getNum_QuartoRes()) == lista_reservas[u].getNum_QuartoRes())
                return false;



}
