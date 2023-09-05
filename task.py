def distribute_money(currency_in_hand, amounts_to_distribute, priority):
    # Create a dictionary to store the distribution of money
    distribution = {p: {} for p in amounts_to_distribute}
    # Iterate through the amounts to distribute
    for i, amount in enumerate(amounts_to_distribute):
        # Iterate through the priority list
        for p in priority:
            # If the current currency is less than or equal to the amount and there are enough notes in hand
            if p <= amount and currency_in_hand[p] > 0:
                # Calculate the number of notes needed
                notes_needed = amount // p
                # Check if there are enough notes in hand
                if notes_needed <= currency_in_hand[p]:
                    # Deduct the notes from the currency in hand
                    currency_in_hand[p] -= notes_needed
                    # Add the notes to the distribution
                    distribution[amount][p] = notes_needed
                    # Deduct the amount from the total amount
                    amount -= notes_needed * p
                else:
                    # Deduct the notes from the currency in hand
                    currency_in_hand[p] = 0
                    # Add the notes to the distribution
                    distribution[amount][p] = notes_needed
                    # Deduct the amount from the total amount
                    amount -= notes_needed * p
    return distribution

# Test the function
currency_in_hand = {2000: 2, 500: 10, 200: 40, 100: 20, 50: 20, 20: 10, 10: 10, 5: 10, 2: 20, 1: 10}
amounts_to_distribute = [1501, 1401, 1107, 1847, 500]
priority = [1, 2, 5, 10, 20, 50, 100, 200, 500, 2000]

distribution = distribute_money(currency_in_hand, amounts_to_distribute, priority)
print(distribution)
