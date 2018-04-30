# aero-simulator

INE 5410 - Programação Concorrente
Trabalho I - Simulador de Aeroporto
Data de Entrega pelo Moodle: 11 de Maio de 2018
Datas de Apresentação: 16 e 18 de Maio de 2018

O Trabalho I do primeiro semestre de 2018 (2018/1) para a disciplina de Programação Concorrente (INE 5410) consiste em desenvolver um sistema concorrente em C utilizando Pthreads que simula o funcionamento de um aeroporto. Nesse sistema existem três recursos principais: 

# i) pistas de pouso e decolagem; 
# ii) portões de embarque e desembarque;
# iii) esteiras de malas. 

Estes recursos do aeroporto são utilizados pelos aviões. A sua solução deverá demonstrar e informar na tela o estado em que se encontra a simulação, indicando os momentos em que os aviões reservam e liberam recursos do aeroporto, de forma que seja possível verificar o funcionamento correto da simulação.

A seguir são apresentadas as principais características de cada um dos elementos pertencentes ao simulador. Todas as medidas de tempo citadas a seguir deverão ser representadas em milissegundos.
Aviões

Aviões são consumidores de recursos do aeroporto e deverão ser representados por threads na sua solução. Basicamente, eles devem realizar a seguinte rotina:

# Aproximação ao aeroporto:
   Primeiramente o avião deverá realizar uma etapa de aproximação, onde aguardará até que uma das pistas de pouso esteja desocupada.
# Pouso:
   Quando uma pista estiver desocupada, o avião deverá então pousar.
# Acoplagem a um portão:
   Após o pouso, o avião deverá se dirigir a um portão de embarque/desembarque.
# Transporte de bagagens: 
   Ao chegar no portão, as bagagens serão removidas do avião e colocadas em uma das esteiras de malas disponíveis no aeroporto. Então, novos passageiros embarcarão no avião e suas bagagens serão transferidas para o avião. O avião deverá liberar o portão de desembarque/embarque quando as malas dos passageiros que estão embarcando tiverem sido colocadas no avião. Para simplificar o problema, considere que todos os passageiros já terão embarcado quando todas as suas malas tiverem sido colocadas no avião.
# Decolagem: 
   Após o transporte de bagagens o avião deverá novamente escolher uma pista para, então, decolar. Você deverá garantir que aviões possam eventualmente decolar, mesmo na presença de aviões em aproximação para pouso.

Aviões (threads) deverão ser criados em intervalos de tempo aleatórios entre NOVO_AVIAO_MIN e NOVO_AVIAO_MAX e deverão iniciar a sua aproximação ao aeroporto imediatamente. Cada avião deverá ser criado com uma quantidade de combustível aleatória em seu tanque entre COMBUSTIVEL_MIN e COMBUSTIVEL_MAX. Aviões deverão finalizar sua execução quando tiverem decolado.
Pistas de pouso e decolagem

Pistas de decolagem e pouso são recursos que devem ser utilizados pelos aviões. As pistas podem ser usadas por apenas um avião de cada vez. Você deverá considerar que o tempo de utilização da pista para decolagem e pouso é fixo (parâmetro TEMPO_POUSO_DECOLAGEM). A sua solução deverá permitir a escolha do número de pistas do aeroporto (parâmetro NUMERO_PISTAS).

Aviões que solicitarem permissão para pouso e estiverem com menos de 10% de combustível no tanque devem ter prioridade sobre todos os demais aviões que estiverem aguardando para pousar ou decolar. Os demais aviões terão permissão para pouso ou decolagem respeitando a ordem de entrada na fila para uso da pista (ordem FIFO).
Portões de embarque e desembarque

Portões de embarque e desembarque também são recursos que devem ser utilizados pelos aviões. Portões só podem ser acessados por aviões que já aterrissaram. A sua solução deverá permitir a escolha do número de portões de embarque/desembarque do aeroporto (parâmetro NUMERO_PORTOES).

# Movimentação de bagagens dos aviões:
   Você deverá considerar um tempo fixo para retirar as bagagens do avião (parâmetro TEMPO_REMOVER_BAGAGENS). Da mesma forma, você deverá assumir um tempo fixo para carregar novas bagagens no avião (parâmetro TEMPO_INSERIR_BAGAGENS). As novas bagagens somente poderão ser carregadas após as bagagens terem sido retiradas do avião. Por fim, é importante notar que um avião só pode ter suas malas retiradas caso haja ao menos uma (1) esteira disponível para colocação das bagagens. Caso contrário, o avião deverá aguardar até que uma esteira possa ser usada para colocação das bagagens.

# Esteiras de malas:
  Esteiras também são recursos que devem ser utilizados pelos aviões. Esteiras só podem ser acessadas por aviões que já pousaram e acessaram um portão de embarque. Diferentemente dos recursos anteriores, as esteiras poderão ser compartilhadas, podendo receber bagagens de diferentes aviões. O número máximo de aviões que poderão usar uma mesma esteira deverá ser especificado pelo parâmetro MAXIMO_AVIOES_ESTEIRA. Quando colocadas em uma esteira, as bagagens de um avião permanecerão nela por um tempo fixo (parâmetro TEMPO_BAGAGENS_ESTEIRA). A sua solução deverá permitir a escolha do número de esteiras do aeroporto (parâmetro NUMERO_ESTEIRAS).

# Código base
  Utilize o código-fonte disponível abaixo como ponto de partida para a sua implementação. 

# Grupos e avaliação
  O trabalho deverá ser realizado em grupos de 2 alunos. Os grupos deverão ser formados com auxílio da ferramenta Escolha de Grupos (T1 - Turma A), no caso de alunos matriculados na Turma A, ou Escolha de Grupos (T1 - Turma B), no caso de alunos matriculados na Turma B. Não será permitida a formação de grupos contendo alunos matriculados em turmas distintas. Os trabalhos serão apresentados nos dias definidos no cronograma disponível no Moodle. O professor irá avaliar a corretude, o desempenho e clareza da solução proposta. A data/hora limite para o envio dos trabalhos é 11/05/2018 às 23h59min. Não será permitida a entrega de trabalhos fora desse prazo. 
      Durante a apresentação, o professor irá avaliar o conhecimento individual dos alunos sobre os conteúdos teóricos e práticos vistos em aula e sobre a solução adotada no trabalho. A nota atribuída à cada aluno i no trabalho (NotaTrabalhoi) será calculada da seguinte forma, onde Ai é a nota referente à apresentação do aluno i e S é a nota atribuída à solução do trabalho:

# NotaTrabalhoi = (Ai * S)/10

  Como indicado pela fórmula mostrada acima, a nota atribuída à solução adotada será ponderada pelo desempenho do aluno durante a apresentação do trabalho. Por exemplo, se o professor atribuir nota 10 para a solução adotada pelo grupo mas o aluno receber nota 5 pela apresentação - devido ao desconhecimento dos conteúdos teóricos, práticos e/ou da solução do trabalho - a sua nota final do trabalho será 5. A ausência no dia da apresentação ou recusa de realização da apresentação do trabalho implicará em nota zero na apresentação, fazendo com que a nota atribuída ao aluno também seja zero.
