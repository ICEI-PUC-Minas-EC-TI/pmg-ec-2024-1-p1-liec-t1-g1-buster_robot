
# Materiais

Os materiais utilizados no projeto foram:
- 4 motores
- 2 placas ESP32
- 2 placas Arduino
- 2 baterias (9 volts)
- 1 pacote de balões
- 1 pacote de espeto
- 2 kits de carro
- 2 servo motors
- Fita dupla face
- Papel panamá
- Papel cartão laminado
- Cola quente
- 2 suportes para balão
- Agulhas

# Desenvolvimento

A primeira etapa foi o desenvolvimento do aplicativo. Após isso foi feito o desenvolvimento do código do carro, e a integração com o aplicativo. Por último foi feito o carro, a integração com o código e a carcaça do carro.

## Desenvolvimento do Aplicativo

### Interface

O desenvolvimento das telas foi feita utilizando utilizando o MIT App Inventor, utilizando os componentes nativos fornecidos pela plataforma.

### Código

O código foi feito com programação em blocos utilizando o MIT App Inventor, com a integração com o robô feita utilizando conexão bluetooth.

## Desenvolvimento do Hardware

### Montagem

O hardware foi feito em duas interface diferentes: para a garra, foi utilizado arduino com o servo. Para as rodas, foi utilizado um esp32, junto com as rodas e os motores. A parte externa foi feita utilizando papel panamá, papel cartão laminado e outros items.

### Desenvolvimento do Código

O código foi feito em dois arquivos. O primeiro pega os dados enviados pelo app e usa para andar com o hardware. O segundo foi para controlar o arduino, fazendo que o servo se movimente em um loop, para movimentar a garra.

## Comunicação entre App e Hardware

A comunicação entre o App e o Hardware é feita usando bluetooth. O app envia para as coordenadas x e y para o hardware, que utiliza como parâmetro para decidir onde vai locomover.
