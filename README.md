# English

### Preface

Thanks to the algorithms of artificial intelligence, today science has reached a stage never imagined by our ancestors: with them, we have solutions to very complicated problems quickly and automatically. 

Neural networks are used in almost every technological sector, reaching heavy industries, startups, product developers, soft-houses, robotics, automotive industries and even for scientific activities, for example in university research groups and machine learning. 

Theoretically, a neural network can learn anything as long as the problem in question is correctly modeled and the learning base is of quality. The challenge for this project is to develop a neural network that can be used in embedded systems with low processing power. But, for example, a PIC18F4550 or an ATMega328p would not be able to find solutions to very complex problems in a reasonably short time. The solution to this is to use a learning transfer concept: A more robust system learns, and that learning would be transferred to the embedded system. With this, the embedded system would process the inputs and generate the outputs, which is something that does not demand much processing power. Robotic problems involving inverse kinematics would be easily solved, for example.

The languages chosen for this project will be C and C ++. The reasons are high portability, seeking to reach the widest range of microcontrollers and due to high performance compared to other languages (such as JAVA, for example), increasing the learning speed and processing of inputs.

### License

##### GNU Lesser General Public License v3.0

Permissions of this copyleft license are conditioned on making available complete source code of licensed works and modifications under the same license or the GNU GPLv3. Copyright and license notices must be preserved. Contributors provide an express grant of patent rights. However, a larger work using the licensed work through interfaces provided by the licensed work may be distributed under different terms and without source code for the larger work.

Permissions:

- Commercial use;
- Modification;
- Distribuition;
- Patent Use;
- Private Use;

Limitations:

- Liability;
- Warranty;

Conditions:

- License and copyright notice;
- Disclose source;
- State changes;
- Same license (library);

For more informations, check the _LICENSE_ document.

### How can I contribute?

You can contribute to this project in several ways:

- Improving the algorithm;
- Fixing bugs;
- Improving documentation;
- Testing the algorithms and reporting errors;
- Solving problems of any kind using this library and sharing the solution to the community;

**Caution:** _Codes follow the **MISRA** pattern. Codes that do not follow this pattern **will not** enter the solution. The only exception is the use of dinamic allocation memory, provided it is used **in the latter case and taking all necessary precautions, such as memory release and use of class destructors.**_

The exception is the use of dynamic memory allocation, but only in the latter case.

# Português

### Introdução

Graças aos algoritmos de inteligência artificial, hoje a ciência chegou em um patamar jamais imaginados pelos nossos antepassados: com elas, temos soluções para problemas complicadíssimos de forma rápida e automática.

As redes neurais são utilizadas em praticamente todo setor tecnológico, atingindo industrias pesadas, startups, empresas desenvolvedores de produtos, soft-houses, robótica, industrias automobilísticas e até mesmo para atividades científicas, como por exemplo em grupos de pesquisas de universidades e aprendizado de máquinas.

Teoricamente, uma rede neural pode aprender qualquer coisa desde que o problema em questão seja modelado corretamente e que a base de aprendizado seja de qualidade.
O desafio para este projeto é desenvolver uma rede neural que poderá ser utilizada em sistemas embarcados de baixo poder de processamento. Mas, por exemplo, um PIC18F4550 ou um ATMega328p não conseguiria achar soluções para problemas muito complexos em um tempo razoavelmente curto. A solução para isso é utilizar um conceito de transferência de aprendizado: Um sistema mais robusto aprende, e esse aprendizado seria transferido para o sistema embarcado. Com isso, o sistema embarcado processaria as entradas e geraria as saídas, que é algo que não demanda muito poder de processamento. Problemas de robótica que envolvem cinemática inversa seriam facilmente resolvidos, por exemplo.

As linguagens escolhidas para este projeto serão C e C++. Os motivos  da escolha são alta portabilidade, procurando atingir a maior gama de microcontroladores e devido à alta performance comparado à outras linguagens (como JAVA, por exemplo), aumentando a velocidade de aprendizado e processamento de entradas;

### Licença

##### Licença Apache 2.0

As permissões desta licença de copyleft estão condicionadas a disponibilizar o código fonte completo de trabalhos licenciados e modificações sob a mesma licença ou a GNU GPLv3. Direitos autorais e avisos de licença devem ser preservados. Os colaboradores fornecem uma concessão expressa de direitos de patente. No entanto, um trabalho maior usando o trabalho licenciado por meio de interfaces fornecidas pelo trabalho licenciado pode ser distribuído sob termos diferentes e sem código-fonte para o trabalho maior.

Permissões:

- Uso comercial;
- Modificações;
- Distribuição;
- Uso em patentes;
- Uso privado;

Limitações:

- Responsabilidade;
- Garantia;

Condições:

- Licença e aviso de direitos autorais;
- Divulgação do código fonte;
- Mudanças de estado;
- Compatibilidade de licenças (para bibliotecas);

Para maiores detalhes, checar o documento _LICENSE_.

### Como posso ajudar?

Você pode contribuir para este projeto de várias maneiras:

- Melhorando o algoritmo;
- Corrigindo bugs;
- Melhorando a documentação;
- Testando os algoritmos e reportando erros;
- Resolvendo problemas de qualquer natureza utilizando essa biblioteca e compartilhando a solução para a comunidade;

**Atenção:** _Os códigos seguem o padrão **MISRA**. Códigos que não seguem esse padrão **não** entrarão na solução. A única exceção é o uso de alocação dinâmica de memória, contando que seja utilizada **em último caso e tomando todas as devidas precauções, como liberação de memória e utilização de destrutores de classes.**_
