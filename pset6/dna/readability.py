def main():
    text = input("Enter some text")
    letter_count = get_letter_count(text)
    word_count = get_word_count(text)
    sentence_count = get_sentence_count(text)
    index = get_index(word_count, letter_count, sentence_count)
    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def get_word_count(text):
    count = 0
    text = text.split(" ")
    return len(text)


def get_letter_count(text):
    count = 0
    for char in text:
        if char.isalnum():
            count += 1
    return count


def get_sentence_count(text):
    count = 0
    for char in text:
        if char == "?" or char == "." or char == "!":
            count += 1
    return count


def get_index(word_count, letter_count, sentence_count):
    multiplier = 100 / word_count
    letter_count_per_word_count = letter_count * multiplier
    sentence_count_per_word_count = sentence_count * multiplier
    float_index = 0.0588 * letter_count_per_word_count - \
        0.296 * sentence_count_per_word_count - 15.8
    rounded_index = round(float_index)
    return rounded_index


main()