(1) Construtores
(2) Métodos

(1) list() // Cria uma list sem espaços alocados
    list<tipo>(int size, tipo conteúdo) /* Atribui um tamanho ao list e preenche 
                                            cada posição com o conteúdo */
    list(list V) // Cria uma cópia de outro list
    list(V.begin(), V.end()) //Cria uma cópia de uma sequência de outro list 	

(2) begin() // Retorna o endereço referente a primeira posição do list
    clear() // Remove todos os elementos do vector e altera seu tamanho para 0
    empty() // Verifica se o tamanho do list é igual a 0 (retorna true caso seja)
    end() // Retorna um iterador referente à posição após o último elemento
    erase(iterator) // Remove um elemento do list, reduzindo o tamanho do mesmo
    erase(iterator ini, iterator end) // Remove uma sequência de de elementos(ini até end)
    insert(iterator pos, tipo elemento) // Insere o elemento uma posição antes de pos
    pop_back() // Remove o último elemento
    pop_front() // Remove o primeiro elemento
    push_back(tipo Valor) /* Adiciona uma posição no final do list e preenche-a
                             com Valor */
    resize(int size) // Altera o tamanho do list para size