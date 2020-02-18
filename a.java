
class Livro
{
    String nome;
    int anoPublicacao;
    String autor;
    String generos;
    Editora editora = new Editora();
    String isbn;
    Float preco;
    int unidadesAcervo = 1;
    int unidadesEmprestadas;
    String relatorio;

    void adicionarNovasQuantidades(int quantidade)
    {
        unidadesAcervo += quantidade;
    }

    // Imprimir todos os dados
    String recuperarDados()
    {
        relatorio = "\n Nome: " + nome;
        relatorio += "\n Ano de Publicação: " + anoPublicacao ;
        relatorio += "\n Autor: " + autor ;
        relatorio += "\n Gênero(s): " + generos;
        relatorio += "\n Editora: " + editora.nome;
        relatorio += "\n Cidade: " + editora.cidade;
        relatorio += "\n ISBN: " + isbn;
        relatorio += "\n Preço: " + preco;
        relatorio += "\n Unidades Acervo: " + unidadesAcervo;
        relatorio += "\n Unidades Emprestadas " + unidadesEmprestadas;

        return relatorio;
    }
    
    boolean emprestar()
    {
        boolean status = false;
        if(unidadesAcervo == unidadesEmprestadas)
        {
            return status;
        }
        else
        {
            this.unidadesEmprestadas ++;
            status = true;
            return status;
        }

    }

    boolean devolver()
    {
        boolean status = false;
        if(unidadesEmprestadas == 0)
        {
            return status;
        }
        else
        {
            this.unidadesEmprestadas --;
            status = true;
            return status;
        }

    }

    String recuperarReferenciaBibliografica()
    {
        //SOBRENOME, Nome(Autor). Obra. Cidade da editora: Editora, Ano de Publicação.
        //ASSIS, Machado. Dom Casmurro. São Paulo: Saraiva, 1891.
        String referencia = "";

        char vetorChar[];
        
        int indiceEspaco = 0;

        vetorChar = autor.toCharArray();

        //Percorrer o vetor de caracteres e guardar o índice do último espaço (" ")
        for(int i = autor.length()-1; i >= 0; i--)
        {
            if(vetorChar[i] == ' ')
            {
                indiceEspaco = i;
                break;
            }
        }

        referencia += autor.substring(indiceEspaco, autor.length() ).toUpperCase();
        referencia += ", "+ autor.substring(0, indiceEspaco) + ". ";
        referencia += nome + ". ";
        referencia += editora.cidade + ": ";
        referencia += editora.nome + ", ";
        referencia += anoPublicacao + ".";

        return referencia;
        
    }
    public static void main(String[] args)
    {


    }
}