int somaDeNumerosInteirosConsecutivos(int num)
{
    int inicio = 1; 
    int final = (num + 1) / 2;
    int resultado = 0;

    while (inicio < final)
    {
        int temporario = 0;
        for (int index = inicio; index <= final; index++)
        {
            temporario += index;

            if(temporario > num) break;

            if(temporario == num)
            {
                resultado++;
                break;
            }
        }
        inicio++;
        temporario = 0;
    }
    return resultado;
}