
Instruções;

    Movimento da Câmera:
        W - Mover para direção que a camera está vendo
        S - Mover ao lado contrário da direção de visão
        D - Mover para direita
        A - Mover para esquerda
        Q - Mover camera para cima
        E - Mover camera para baixo
        Segurar botão esquerdo e mover mouse: Modifica visão da camera

    O - Camera ortografica
    P - Camera perspectiva

    Demais parametros como RPM, sensibilidade do mouse, velocidade de movimento, ativar e desativar componentes do pistão podem ser controlados através da janela de interface.

Observações:
    - O programa demora a iniciar devido ao carregamento dos .obj e das texturas em .BPM, que são de 2K

Requisitos Implementados:
    - Rotação do eixo variável (RPM informada pelo usuário).
    - Visualização ortográfica e perspectiva (sob vários ângulos) em wireframe/preenchimento.
    - Iluminação Difusa (Goraud Shading).
    - Movimentação da câmera com a LookAt, com uso do mouse e teclado.
    - Controle de FPS

Extras:

    1 - Texturização -> Diffuse/Albedo mapping (fonte: https://learnopengl.com/Lighting/Lighting-maps)
    2 - Carregamento de Texturas .BMP
    3 - Carregamento de Malhas no formato .OBJ
    4 - Mais de 1 Pistão (3)
    5 - Redimensionamento da tela com correção de aspect ratio
    6 - Uso do Pipeline Programavel introduzido na OpenGL 3.1
    7 - Uso de Shaders rodando na GPU (Vertex Shader e Fragment Shader)
    8 - Uso da biblioteca gráfica ImGui para criação de interface de usuário.