def main():
    size_check = get_number()
    if size_check == False:
        return 1
    luhn_check = luhn_alg(size_check)
    if luhn_check == False:
        return 1
    discover_flag(size_check)


def get_number():
    # Obtém o input do usuário, que deve ser entre 13 e 16 números
    # Se for menor que 13 ou maior que 16, deve printar INVALID e retornar 1
    # Se não, retorna o input.
    card = int(input("Qual o número do cartão?"))
    size = len(str(card))
    if size == 13 or size == 15 or size == 16:
        return card
    else:
        print("INVALID")
        return False


def luhn_alg(card):
    # Calcula o algoritmo de Luhn para saber se é um cartão válido
    # Se for inválido, deve printar INVALID e retornar False
    # Se não, retorna True
    str_card = list(str(card))
    str_card.reverse()

    sum_pair = 0  # Total da soma dos dígitos dos números pares a partir do penúltimo * 2
    sum_unpaired = 0  # Total da soma dos números ímpares a partir do último
    for i in range(1, (len(str_card)), 2):  # Iterando os pares
        str_double = str(int(str_card[i]) * 2)  # Multiplica por 2
        sum_pair += sum(int(x) for x in str_double)  # Soma os dígitos e acrescenta à variável dos pares
    for j in range(0, (len(str_card)), 2):  # Iterando os ímpares
        sum_unpaired += int(str_card[j])  # Acrescenta aos ímpares

    total_list = list(str(sum_pair + sum_unpaired))  # Cria uma lista com a soma dos pares e ímpares calculados
    total = int(total_list[-1])  # Obtém o último número e confere se é igual a 0

    if total != 0:
        print("INVALID_LUHN")
        return False


def discover_flag(card_number):
    # Verifica se os primeiros dígitos correspondem a alguma bandeira
    # AMEX = 15 Dígitos e começa com 34 OU 37;
    # MASTERCARD = 16 Dígitos e começa com 51, 52, 53, 54 ou 55
    # VISA = 13 ou 16 dígitos e começa com 4
    card = list(str(card_number))
    card_0 = int(card[0])
    card_1 = int(card[1])
    len_card = len(card)
    if len_card == 15 and card_0 == 3 and (card_1 == 4 or card_1 == 7):
        print("AMEX")
    elif len_card == 13 and card_0 == 4:
        print("VISA")
    elif len_card == 16 and card_0 == 4:
        print("VISA")
    elif len_card == 16 and card_0 == 5 and (card_1 == 1 or card_1 == 2 or card_1 == 3 or card_1 == 4 or card_1 == 5):
        print("MASTERCARD")
    else:
        print("INVALID")


main()