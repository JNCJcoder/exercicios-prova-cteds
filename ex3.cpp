#include <string>

using std::string;

string conjuntos(string operacao)
{
    bool dentroDeChave = false;
    int conjuntoAtual = 0;
    string operador;
    string conjuntoUm;
    string conjuntoDois;
    string resultado;

    for(char& caractere : operacao)
    {
        switch (caractere)
        {
            case '{':
                conjuntoAtual++;
                dentroDeChave = true;
            break;

            case '}':
                dentroDeChave = false;
            break;

            case ' ':
                if(dentroDeChave == true) return "";
            break;

            case '+':
            case '-':
            case '*':
                if(dentroDeChave == true) return "";
                if(operador == "+" || operador == "-" || operador == "*") return "";
                operador = caractere;
            break;

            default:
                if(caractere < 'A' || caractere > 'Z')  return "";
                if(conjuntoAtual == 0)  return "";
                if(conjuntoAtual > 2)   return "";

                if(conjuntoAtual == 1) conjuntoUm.push_back(caractere);
                if(conjuntoAtual == 2) conjuntoDois.push_back(caractere);
            break;
        }
    }

    resultado.append("{");
    switch (*operador.c_str())
    {
        case '+':
        {
            string temporario;
            temporario.append(conjuntoUm);
            temporario.append(conjuntoDois);

            for(char& caractere : temporario)
            {
                if(resultado.find(caractere) == std::string::npos)
                {
                    resultado += caractere;
                }
            }
            break;
        }

        case '-':
        {
            for(char& caractere : conjuntoDois)
            {
                size_t pos = conjuntoUm.find(caractere);
                if (pos == std::string::npos) continue;
                conjuntoUm.erase(pos, 1);
            }
            resultado.append(conjuntoUm);
            break;
        }

        case '*':
        {
            for(char& caractere : conjuntoUm)
            {
                size_t pos = conjuntoDois.find(caractere);
                if (pos != std::string::npos)
                {
                    resultado += caractere;
                }
            }
            break;
        }

        default: return "";
    }
    resultado.append("}");

    return resultado;
}
