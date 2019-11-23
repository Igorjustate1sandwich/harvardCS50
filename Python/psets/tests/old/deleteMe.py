import sys
import crypt
import time
start_time = time.time()

# todo: REVERSE LOOP ORDER TO SEE SPEED DIF

def main():

    ahash = "50zY5U41rvZV."
    salt = "50"
    letters = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

    for first in letters:
        for second in letters:
            for third in letters:
                for fourth in letters:
                    for fifth in letters[1:]:
                        candidate = f"{first}{second}{third}{fourth}{fifth}".strip()
                        
                        if crypt.crypt(candidate, salt) == ahash:
                            print(candidate)
                            print(f"***** OTHER Cracked in {time.time() - start_time:.4f} seconds *****\n")
                            sys.exit(0)
                        print(candidate)


if __name__ == "__main__":
    main()