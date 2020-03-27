#include "definicoes.h"

void readStocks(wallet &referencia, stock *acoes)
{
    acoes->read(FOLDER "ABEV3.data", "Ambev");
    referencia.insert(*acoes, 0.050349);
    acoes++;

    acoes->read(FOLDER "BBAS3.data", "Banco do Brasil");
    referencia.insert(*acoes, 0.033529);
    acoes++;

    acoes->read(FOLDER "BBDC3.data", "Banco Bradesco");
    referencia.insert(*acoes, 0.018603);
    acoes++;

    acoes->read(FOLDER "BBDC4.data", "Banco Bradesco");
    referencia.insert(*acoes, 0.071608);
    acoes++;

    acoes->read(FOLDER "BBSE3.data", "BB Seguridade");
    referencia.insert(*acoes, 0.015799);
    acoes++;

    acoes->read(FOLDER "BEEF3.data", "Minerva Foods");
    referencia.insert(*acoes, 0.001930);
    acoes++;

    acoes->read(FOLDER "BPAN4.data", "Banco PAN");
    referencia.insert(*acoes, 0.001537);
    acoes++;

    acoes->read(FOLDER "BRAP4.data", "Bradespar");
    referencia.insert(*acoes, 0.005201);
    acoes++;

    acoes->read(FOLDER "BRFS3.data", "Perdigao");
    referencia.insert(*acoes, 0.011029);
    acoes++;

    acoes->read(FOLDER "BRKM5.data", "Braskem");
    referencia.insert(*acoes, 0.003000);
    acoes++;

    acoes->read(FOLDER "BRML3.data", "BR MALLS");
    referencia.insert(*acoes, 0.006676);
    acoes++;

    acoes->read(FOLDER "BRSR6.data", "BANRISUL");
    referencia.insert(*acoes, 0.002324);
    acoes++;

    acoes->read(FOLDER "BTOW3.data", "B2W Digital");
    referencia.insert(*acoes, 0.009197);
    acoes++;

    acoes->read(FOLDER "CCRO3.data", "Grupo CCR");
    referencia.insert(*acoes, 0.011103);
    acoes++;

    acoes->read(FOLDER "CESP6.data", "CESP");
    referencia.insert(*acoes, 0.011103);
    acoes++;

    acoes->read(FOLDER "CIEL3.data", "Cielo");
    referencia.insert(*acoes, 0.004758);
    acoes++;

    acoes->read(FOLDER "CMIG3.data", "CEMIG");
    referencia.insert(*acoes, 0.002004);
    acoes++;

    acoes->read(FOLDER "CMIG4.data", "CEMIG");
    referencia.insert(*acoes, 0.008287);
    acoes++;

    acoes->read(FOLDER "CPFE3.data", "CPFL Energia");
    referencia.insert(*acoes, 0.004131);
    acoes++;

    acoes->read(FOLDER "CPLE6.data", "AC. COPEL");
    referencia.insert(*acoes, 0.006062);
    acoes++;

    acoes->read(FOLDER "CSAN3.data", "Cosan");
    referencia.insert(*acoes, 0.033529);
    acoes++;

    acoes->read(FOLDER "CSMG3.data", "CSMG");
    referencia.insert(*acoes, 0.002410);
    acoes++;

    acoes->read(FOLDER "CSNA3.data", "Companhia Siderurgica Nacional");
    referencia.insert(*acoes, 0.003799);
    acoes++;

    acoes->read(FOLDER "CVCB3.data", "CVC Brasil");
    referencia.insert(*acoes, 0.001143);
    acoes++;

    acoes->read(FOLDER "CYRE3.data", "Cyrela Brazil");
    referencia.insert(*acoes, 0.003590);
    acoes++;

    acoes->read(FOLDER "DTEX3.data", "Duratex");
    referencia.insert(*acoes, 0.002398);
    acoes++;

    acoes->read(FOLDER "ECOR3.data", "EcoRodovias");
    referencia.insert(*acoes, 0.001500);
    acoes++;

    acoes->read(FOLDER "ELET3.data", "Centrais Eletricas Brasileiras");
    referencia.insert(*acoes, 0.005250);
    acoes++;

    acoes->read(FOLDER "ELET6.data", "Centrais Eletricas Brasileiras");
    referencia.insert(*acoes, 0.004107);
    acoes++;

    acoes->read(FOLDER "EMBR3.data", "Embraer");
    referencia.insert(*acoes, 0.005939);
    acoes++;

    acoes->read(FOLDER "ENBR3.data", "EDP Brasil");
    referencia.insert(*acoes, 0.004070);
    acoes++;

    acoes->read(FOLDER "ENGI11.data", "Grupo Energisa");
    referencia.insert(*acoes, 0.009258);
    acoes++;

    acoes->read(FOLDER "EQTL3.data", "Equatorial Energia");
    referencia.insert(*acoes, 0.016758);
    acoes++;

    acoes->read(FOLDER "EZTC3.data", "EZ TEC");
    referencia.insert(*acoes, 0.002754);
    acoes++;

    acoes->read(FOLDER "FLRY3.data", "Fleury");
    referencia.insert(*acoes, 0.005619);
    acoes++;

    acoes->read(FOLDER "GGBR4.data", "Gerdau");
    referencia.insert(*acoes, 0.009160);
    acoes++;

    acoes->read(FOLDER "GOAU4.data", "Metalurgica Gerdau");
    referencia.insert(*acoes, 0.002643);
    acoes++;

    acoes->read(FOLDER "GOLL4.data", "GOL Linhas Aereas");
    referencia.insert(*acoes, 0.000947);
    acoes++;

    acoes->read(FOLDER "HGTX3.data", "CIA Hering");
    referencia.insert(*acoes, 0.001648);
    acoes++;

    acoes->read(FOLDER "HYPE3.data", "Hypera Pharma");
    referencia.insert(*acoes, 0.011447);
    acoes++;

    acoes->read(FOLDER "IGTA3.data", "Iguatemi Empresa de Shopping Centers");
    referencia.insert(*acoes, 0.002336);
    acoes++;

    acoes->read(FOLDER "ITSA4.data", "Itausa");
    referencia.insert(*acoes, 0.035890);
    acoes++;

    acoes->read(FOLDER "ITUB4.data", "Itau Unibanco");
    referencia.insert(*acoes, 0.100391);
    acoes++;

    acoes->read(FOLDER "JBSS3.data", "JBS");
    referencia.insert(*acoes, 0.029865);
    acoes++;

    acoes->read(FOLDER "KLBN11.data", "Kablin");
    referencia.insert(*acoes, 0.008435);
    acoes++;

    acoes->read(FOLDER "LAME4.data", "Lojas Americanas");
    referencia.insert(*acoes, 0.011779);
    acoes++;

    acoes->read(FOLDER "LCAM3.data", "Locamerica");
    referencia.insert(*acoes, 0.003074);
    acoes++;

    acoes->read(FOLDER "LIGT3.data", "Light");
    referencia.insert(*acoes, 0.002557);
    acoes++;

    acoes->read(FOLDER "LINX3.data", "Linx");
    referencia.insert(*acoes, 0.003012);
    acoes++;

    acoes->read(FOLDER "LREN3.data", "Lojas Renner");
    referencia.insert(*acoes, 0.025832);
    acoes++;

    acoes->read(FOLDER "MDIA3.data", "M DIAS BRANCO");
    referencia.insert(*acoes, 0.002484);
    acoes++;

    acoes->read(FOLDER "MGLU3.data", "Magazine Luiza");
    referencia.insert(*acoes, 0.019488);
    acoes++;

    acoes->read(FOLDER "MRFG3.data", "Marfrig");
    referencia.insert(*acoes, 0.002889);
    acoes++;

    acoes->read(FOLDER "MRVE3.data", "MRV");
    referencia.insert(*acoes, 0.003221);
    acoes++;

    acoes->read(FOLDER "MULT3.data", "Multiplan");
    referencia.insert(*acoes, 0.004943);
    acoes++;

    acoes->read(FOLDER "MYPK3.data", "Iochpe-Maxion");
    referencia.insert(*acoes, 0.001525);
    acoes++;

    acoes->read(FOLDER "ODPV3.data", "Odontoprev");
    referencia.insert(*acoes, 0.003283);
    acoes++;

    acoes->read(FOLDER "PETR3.data", "Petroleo Brasileiro");
    referencia.insert(*acoes, 0.034636);
    acoes++;

    acoes->read(FOLDER "PETR4.data", "Petroleo Brasileiro");
    referencia.insert(*acoes, 0.052120);
    acoes++;

    acoes->read(FOLDER "PSSA3.data", "Porto Seguro");
    referencia.insert(*acoes, 0.004389);
    acoes++;

    acoes->read(FOLDER "QUAL3.data", "Qualicorp");
    referencia.insert(*acoes, 0.005791);
    acoes++;

    acoes->read(FOLDER "RADL3.data", "RaiaDrogasil");
    referencia.insert(*acoes, 0.023054);
    acoes++;

    acoes->read(FOLDER "RAPT4.data", "Randon");
    referencia.insert(*acoes, 0.000848);
    acoes++;

    acoes->read(FOLDER "RENT3.data", "Localiza Hertz");
    referencia.insert(*acoes, 0.014840);
    acoes++;

    acoes->read(FOLDER "SANB11.data", "Banco Santander");
    referencia.insert(*acoes, 0.008963);
    acoes++;

    acoes->read(FOLDER "SBSP3.data", "CSBSP");
    referencia.insert(*acoes, 0.011017);
    acoes++;

    acoes->read(FOLDER "SLCE3.data", "SLC Agricola");
    referencia.insert(*acoes, 0.001611);
    acoes++;

    acoes->read(FOLDER "SULA11.data", "Sul America");
    referencia.insert(*acoes, 0.008053);
    acoes++;

    acoes->read(FOLDER "TAEE11.data", "TAESA");
    referencia.insert(*acoes, 0.005471);
    acoes++;

    acoes->read(FOLDER "TIMP3.data", "TOM Brasil");
    referencia.insert(*acoes, 0.010771);
    acoes++;

    acoes->read(FOLDER "TOTS3.data", "Totvs");
    referencia.insert(*acoes, 0.005656);
    acoes++;

    acoes->read(FOLDER "TRPL4.data", "CTEEP");
    referencia.insert(*acoes, 0.006848);
    acoes++;

    acoes->read(FOLDER "UGPA3.data", "Grupo Ultra");
    referencia.insert(*acoes, 0.012861);
    acoes++;

    acoes->read(FOLDER "USIM5.data", "AC. USIMINAS");
    referencia.insert(*acoes, 0.002127);
    acoes++;

    acoes->read(FOLDER "VALE3.data", "Vale");
    referencia.insert(*acoes, 0.106785);
    acoes++;

    acoes->read(FOLDER "VIVT4.data", "Telefonica Brasil");
    referencia.insert(*acoes, 0.021332);
    acoes++;

    acoes->read(FOLDER "VVAR3.data", "Via Varejo");
    referencia.insert(*acoes, 0.005484);
    acoes++;

    acoes->read(FOLDER "WEGE3.data", "WEG");
    referencia.insert(*acoes, 0.023029);
}

void createRandonWallet(wallet &carteira, stock *acoes, bool *flag, size_t total_number_of_stocks, size_t number_of_stocks)
{
    carteira.acoes.clear();
    carteira.porcentagem.clear();

    if( number_of_stocks>total_number_of_stocks )
    {
        number_of_stocks = total_number_of_stocks;
        while( number_of_stocks-- )
            carteira.insert(acoes[number_of_stocks]);
        return;
    }

    size_t i;

    for(i=0; i<total_number_of_stocks; i++)
        flag[i] = 0;
    while( number_of_stocks-- )
    {
        do {i = static_cast<size_t>(rand())%total_number_of_stocks;} while (flag[i]);
        flag[i] = 1;

        carteira.insert(acoes[i]);
    }
}
