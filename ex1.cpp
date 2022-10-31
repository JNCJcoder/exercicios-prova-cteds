int concatenarNumeros(int num1, int num2)
{
    int temporario = num2;
    while (temporario)
    {
        num1 *= 10;
        temporario /= 10;
    }
    return num1 + num2;
}

int sobeUm(int num1, int num2)
{
    int temporario = 0;
    int resultado = 0;
    int numero = concatenarNumeros(num1, num2);

    while(numero)
    {
        temporario += numero % 10;
        if(temporario >= 10)
        {
            resultado++;
            temporario -= 10;
        }
        numero /= 10;
    }

    return resultado;
}