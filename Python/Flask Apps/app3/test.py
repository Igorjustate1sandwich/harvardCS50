from werkzeug.security import check_password_hash, generate_password_hash

p1 = "hello"
p2 = "heLLO"
p3 = ''


hash1 = generate_password_hash(p1,'pbkdf2:sha256', salt_length=8)


print(hash1)