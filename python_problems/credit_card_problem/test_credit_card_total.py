import pytest
from credit_card_total import bill_calculation


def test_single_store(tmp_path):
    file = tmp_path / "bill.txt"

    file.write_text(
        "1[Amazon] $100\n"
        "2[Amazon] $200\n"
    )

    assert bill_calculation(file) == {
        "Amazon": 300
    }


def test_multiple_stores(tmp_path):
    file = tmp_path / "bill.txt"

    file.write_text(
        "1[Amazon] $100\n"
        "2[Walmart] $50\n"
        "3[Amazon] $200\n"
    )

    assert bill_calculation(file) == {
        "Amazon": 300,
        "Walmart": 50
    }
