(1) Construtores
(2) Métodos

(1) vector() // Cria um vector sem espaços alocados
    vector(int size) // Atribui um tamanho inicial ao vector
    vector<tipo>(int size, tipo conteúdo) /* Atribui um tamanho ao vector e preenche 
                                            cada posição com o conteúdo */
    vector(vector V) // Cria uma cópia de outro vector

(2) begin() // Retorna o endereço referente a primeira posição do vector
    clear() // Remove todos os elementos do vector e altera seu tamanho para 0
    empty() // Verifica se o tamanho do vector é igual a 0 (retorna true caso seja)
    end() // Retorna um iterador referente à posição após o último elemento
    erase(iterator) // Remove um elemento do Vector, reduzindo o tamanho do mesmo
    erase(iterator ini, iterator end) // Remove uma sequência de de elementos(ini até end)
    insert(iterator pos, tipo elemento) /* Insere o elemento uma posição antes de pos
    pop_back() // Remove o último elemento
    pop_front() // Remove o primeiro elemento
    push_back(tipo Valor) /* Adiciona uma posição no final do vector e preenche-a
                             com Valor */
    resize(int size) // Altera o tamanho do vector para size