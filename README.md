# Totem CheckSaúde

## O problema
Nos hospitais brasileiros, a escassez de recursos, especialmente profissionais de saúde, frequentemente desafia a capacidade de atender a todos os pacientes de maneira imediata. Para otimizar o atendimento, é essencial realizar uma triagem eficiente, priorizando casos de acordo com sua urgência. Atualmente, muitos hospitais adotam o Protocolo de Manchester, uma metodologia que utiliza pulseiras coloridas para classificar o risco dos pacientes.
Este protocolo atribui cores específicas a diferentes níveis de urgência:

| Cores    | Urgência      | Tempo de espera      |
| -------- |:-------------:| -------------------- |
| Azul     | Não urgente   | até 240 minutos      |
| Verde    | Pouco urgente | até 120 minutos      |
| Amarelo  | Urgente       | até 60 minutos       |
| Laranja  | Muito urgente | até 10 minutos       |
| Vermelho | Emergente     | atendimento imediato |

A classificação de risco considera diversos fatores, como dor, sinais vitais, pressão e sintomas. A triagem visa organizar o atendimento, proporcionando suporte eficiente e rápido.

## A solução
Utilizei o sensor DHT22 para simular um termômetro, capaz de verificar se o paciente apresenta sinais de hipotermia ou febre ao chegar ao posto. Os dois potenciômetros foram designados como medidores de pressão sistólica (a pressão nos vasos sanguíneos quando o coração se contrai) e diastólica (a pressão nos vasos quando o coração relaxa). Ambos são fundamentais para avaliar se o paciente está sofrendo de hipertensão leve, moderada ou grave.
Integrei um microfone para reconhecimento de fala durante o processo de "login" no totem. Esse recurso não apenas facilita a autenticação do usuário, mas também possibilita a detecção de possíveis dificuldades na fala, indicativas de confusão mental. O segundo microfone foi destinado a simular uma câmera, que capturará uma imagem para o cadastro do paciente. Além disso, será utilizado para verificar se há sinais de palidez cutânea ou dilatação da pupila no paciente.

## Aplicações
#### Componentes Hardware
* 1x Placa wireless - ESP32
* 1x DHT22
* 2x Potenciômetro
* 2x Microfone
#### Funcionamento
Utilizei o sensor DHT22 para representar a utilização de um termômetro, que medirá se o paciente chegou no posto com hipotermia ou febre. Os dois potenciômetros representam medidores de pressão sistólica (pressão nos vasos, quando o coração se contrai) e diastólica (pressão nos vasos quando o coração relaxa). Ambas importantes para saber se o paciente está com hipertensão leve, moderada ou grave. Um microfone será utilizado para reconhecimento de fala ao realizar o "login" no totem, que também aproveitará para avaliar se a fala está embolada ou o usuário está com algum tipo de confusão mental. O outro microfone foi utilizado para representar a câmera, que tirará uma foto para o cadastro do paciente e aproveitará para verificar se ele está apresentando palidez cultânea ou com a pupila dilatada. Todas essas informações são enviadas para o tago, que mostra visualmente em um dashboard a situação do paciente, conforme imagem abaixo:

## Simulação
[Clique aqui para visualizar](https://wokwi.com/projects/382153828426797057)
