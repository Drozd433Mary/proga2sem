import unittest
from src.code import generate_code
class TestCode(unittest.TestCase):
    def test_nchstr(self):
        # тест для нечетных строк (все #)
        result = generate_code(1, 3)
        self.assertEqual(result, ['###'])

        result = generate_code(3, 4)
        self.assertEqual(result, ['####', '...#', '####'])

    def test_chstr(self):
        # тест для четных строк (чередование # и .)
        result = generate_code(2, 4)
        self.assertEqual(result, ['####', '...#'])

        result = generate_code(4, 5)
        self.assertEqual(result, ['#####', '....#', '#####', '#....'])

    def test_onestr(self):
        # тест для одной строки
        result = generate_code(1, 2)
        self.assertEqual(result, ['##'])
if __name__ == '__main__':
    unittest.main()
