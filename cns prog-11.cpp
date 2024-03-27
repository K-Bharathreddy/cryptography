def encrypt_rail_fence(plain_text, rails):
    fence = [['\n' for i in range(len(plain_text))] for j in range(rails)]
    direction_down = False
    row, col = 0, 0

    for char in plain_text:
        if row == 0 or row == rails - 1:
            direction_down = not direction_down
        fence[row][col] = char
        col += 1
        if direction_down:
            row += 1
        else:
            row -= 1

    cipher_text = []
    for i in range(rails):
        for j in range(len(plain_text)):
            if fence[i][j] != '\n':
                cipher_text.append(fence[i][j])
    return''.join(cipher_text)


def decrypt_rail_fence(cipher_text, rails):
    fence = [['\n' for i in range(len(cipher_text))] for j in range(rails)]
    direction_down = None
    row, col = 0, 0

    for char in range(len(cipher_text)):
        if row == 0:
            direction_down = True
        if row == rails - 1:
            direction_down = False

        fence[row][col] = '*'
        col += 1

        if direction_down:
            row += 1
        else:
            row -= 1

    index = 0
    for i in range(rails):
        for j in range(len(cipher_text)):
            if fence[i][j] == '*' and index < len(cipher_text):
                fence[i][j] = cipher_text[index]
                index += 1

    plain_text = []
    row, col = 0, 0
    for char in range(len(cipher_text)):
        if row == 0:
            direction_down = True
        if row == rails - 1:
            direction_down = False

        if fence[row][col] != '*':
            plain_text.append(fence[row][col])
            col += 1

        if direction_down:
            row += 1
        else:
            row -= 1

    return ''.join(plain_text)


# Example usage:
message = "Hello, World!"
rails = 3
encrypted_message = encrypt_rail_fence(message, rails)
print("Encrypted:", encrypted_message)

decrypted_message = decrypt_rail_fence(encrypted_message, rails)
print("Decrypted:", decrypted_message)
