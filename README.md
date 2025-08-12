# boot_swap_utility
A utility to overwrite an automotive bootloader

Boot Swap Utility

During my work as a Senior Software Engineer at a global OEM, as a member of the Infrastructure Software team, I owned Memory Manager and Bootloader. I was tasked with hacking a dev tool for Bootloader. Usually the first rule of Bootloader is "don't overwrite Bootloader", meaning, ensure there are protections in place to avoid accidentally overwriting Bootloader.

But in this case, overwriting it for development purposes is exactly what is being requested. Fortunately, I found a "feature" called "download and execute" that was exactly what I needed to make this an easy assignment. This is the sort of thing that a hacker would consider a dream exploit. I'm sure this sort of vulnerability has been removed by now, but at the time it was exactly what I needed.

Background - What is a Bootloader ?

In the automotive industry, a bootloader is a critical piece of embedded software that initializes a vehicle’s electronic control unit (ECU) and enables secure and reliable firmware updates. Upon power-up, the bootloader verifies system integrity, establishes communication with diagnostic tools or over-the-air update systems, and determines whether to launch the main application or enter programming mode. Automotive bootloaders often comply with ISO 26262 for functional safety and support UDS (Unified Diagnostic Services) over CAN, LIN, or Ethernet. They are designed with robust security features such as cryptographic authentication and secure boot to prevent unauthorized access or tampering with ECU software, ensuring safe and compliant vehicle operation.


