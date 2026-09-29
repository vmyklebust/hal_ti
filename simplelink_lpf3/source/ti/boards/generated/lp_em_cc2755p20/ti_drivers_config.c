/*
 *  ======== ti_drivers_config.c ========
 *  Configured TI-Drivers module definitions
 *
 *  DO NOT EDIT - This file is generated for the LP_EM_CC2755P20
 *  by the SysConfig tool.
 */

#include <stddef.h>
#include <stdint.h>

#ifndef DeviceFamily_CC27XXX20
#define DeviceFamily_CC27XXX20
#endif

#include <ti/devices/DeviceFamily.h>

#include "ti_drivers_config.h"

/*
 *  =============================== Power ===============================
 */
#include <ti/drivers/Power.h>
#include "ti_drivers_config.h"
#include DeviceFamily_constructPath(driverlib/ckmd.h)
#include DeviceFamily_constructPath(driverlib/pmctl.h)

extern void customPolicyFxn(void);

const uint32_t PowerLPF3_capArrayP0 = 553648128; /* floor(8.25 * 2^26) */
const uint32_t PowerLPF3_capArrayP1 = 4697620; /* floor(0.07 * 2^26) */
const uint8_t  PowerLPF3_capArrayShift = 26;  /* shift-value to bring floating-point coefficients to fixed-point */


const PowerCC27XX_Config PowerCC27XX_config = {
    .policyInitFxn              = NULL,
    .policyFxn                  = customPolicyFxn,
    .startInitialHfxtAmpCompFxn = NULL,
};

/*
 * ======== RCL Regulatory Domain Configuration ========
 */
#if defined(CONFIG_SOC_CC2755P10) || defined(CONFIG_SOC_CC2755R10) || defined(CONFIG_SOC_CC2745R10_Q1) || defined(CONFIG_SOC_CC2755P20)

#include <zephyr/kernel.h>
#include <ti/drivers/rcl/RCL_Feature.h>

#define RCL_REGULATORY_MASK \
    ((IS_ENABLED(CONFIG_RCL_REGULATORY_DOMAIN_ETSI) ? (RCL_REGULATORY_DOMAIN_ETSI) : 0U) | \
     (IS_ENABLED(CONFIG_RCL_REGULATORY_DOMAIN_FCC)  ? (RCL_REGULATORY_DOMAIN_FCC) : 0U)  | \
     (IS_ENABLED(CONFIG_RCL_REGULATORY_DOMAIN_MIIT) ? (RCL_REGULATORY_DOMAIN_MIIT) : 0U))

#if defined(CONFIG_SOC_CC2755P10) || defined(CONFIG_SOC_CC2755P20)
const RCL_FeatureControl rclFeatureControl =
{
    .enableTemperatureMonitoring = true,
    .enablePaEsdProtection = false,
    .enableTxOutputPowerCompensation = true
};
#endif /* CONFIG_SOC_CC2755P10 || CONFIG_SOC_CC2755P20 */

#if defined(CONFIG_RCL_REGULATORY_DOMAIN_RUNTIME_MODIFIABLE)
uint8_t rclRegulatoryMask = RCL_REGULATORY_MASK;
#else
const uint8_t rclRegulatoryMask = RCL_REGULATORY_MASK;
#endif

#endif /* CONFIG_SOC_CC2755P10 || CONFIG_SOC_CC2755R10 || CONFIG_SOC_CC2745R10_Q1 || CONFIG_SOC_CC2755P20 */

/*
 * ======== RCL GPIO Configuration ========
 */

__attribute__((weak)) void RCL_GPIO_appEnable(void)
{
}

__attribute__((weak)) void RCL_GPIO_appDisable(void)
{
}

void RCL_GPIO_enable (void)
{
    RCL_GPIO_appEnable();
}

void RCL_GPIO_disable (void)
{
    RCL_GPIO_appDisable();
}

/*
 *  =============================== BatMon Support ===============================
 */
#include <ti/drivers/batterymonitor/BatMonSupportLPF3.h>

#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(inc/hw_ints.h)
#include DeviceFamily_constructPath(driverlib/evtsvt.h)

const BatMonSupportLPF3_Config BatMonSupportLPF3_config = {
    .intNum = INT_CPUIRQ2,
    .intPriority = (~0),
    .intSubscriberId = EVTSVT_SUB_CPUIRQ2,
};
