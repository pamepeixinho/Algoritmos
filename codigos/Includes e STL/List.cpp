(1) Construtores
(2) M�todos

(1) list() // Cria uma list sem espa�os alocados
    list<tipo>(int size, tipo conte�do) /* Atribui um tamanho ao list e preenche 
                                            cada posi��o com o conte�do */
    list(list V) // Cria uma c�pia de outro list
    list(V.begin(), V.end()) //Cria uma c�pia de uma sequ�ncia de outro list 	

(2) begin() // Retorna o endere�o referente a primeira posi��o do list
    clear() // Remove todos os elementos do vector e altera seu tamanho para 0
    empty() // Verifica se o tamanho do list � igual a 0 (retorna true caso seja)
    end() // Retorna um iterador referente � posi��o ap�s o �ltimo elemento
    erase(iterator) // Remove um elemento do list, reduzindo o tamanho do mesmo
    erase(iterator ini, iterator end) // Remove uma sequ�ncia de de elementos(ini at� end)
    insert(iterator pos, tipo elemento) // Insere o elemento uma posi��o antes de pos
    pop_back() // Remove o �ltimo elemento
    pop_front() // Remove o primeiro elemento
    push_back(tipo Valor) /* Adiciona uma posi��o no final do list e preenche-a
                             com Valor */
    resize(int size) // Altera o tamanho do list para size