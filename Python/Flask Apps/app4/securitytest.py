from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

password = "123"

hash = generate_password_hash(password, 'pbkdf2:sha256', salt_length=8)

print(hash)

password2 = "123"
check = check_password_hash(hash, password2)

print(check)