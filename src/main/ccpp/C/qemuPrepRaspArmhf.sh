#/bin/bash

mkdir -p mnt/p1
mkdir -p mnt/p2

echo 0 | sudo -S mount -o loop,offset=4194304 2024-10-22-raspios-bookworm-armhf.img mnt/p1

cp mnt/p1/bcm2709-rpi-2-b.dtb bcm2709-rpi-2-b.dtb
cp mnt/p1/kernel8.img kernel8.img

echo 0 | sudo -S touch mnt/p1/ssh
echo 0 | sudo -S touch mnt/p1/userconf
echo 0 | sudo -S echo 'zero:$6$nKazTU9UYkZ15LbS$aKazZgSp5z/ynlHPrDeaE7x5h4AF3bkioe0cJ02eGR7P75HEEOwaJGcunbh/bCzJipC/6UTT/Lh5KC8lhRaJP0' | sudo tee mnt/p1/userconf

echo 0 | sudo umount mnt/p1

qemu-img resize -f raw 2024-10-22-raspios-bookworm-armhf.img 8G
