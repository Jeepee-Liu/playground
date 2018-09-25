import urllib



def main():
    value = 1000000000000
    site = "https://blockchain.info/tobtc?currency=USD&value={0}"
    site = site.format(value)
    print(site)

if __name__ == '__main__':
    main()
