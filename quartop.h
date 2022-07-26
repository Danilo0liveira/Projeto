#ifndef quartop_h
#define quartop_h

class Quarto_premium : public Quarto{
    private:    
        int ar_cnd, chuv_el, servico, tv, wifi;

    public:
        Quarto_premium(int, int, int, float, int, bool);

        void setAR_CND(int);
        void setC_EL(int);
        void setServico(int);
        void setTV(int);
        void setWifi(int);

        int getAR_CND() const;
        int getC_EL() const;
        int getServico() const;
        int getTV() const;
        int getWifi() const;
        
};

#endif 