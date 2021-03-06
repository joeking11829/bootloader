/* uboot/drivers/video_sunxi/de_bsp/lcd/lcd_source_interface.h
 *
 * Copyright (c) 2013 Allwinnertech Co., Ltd.
 * Author: Tyle <tyle@allwinnertech.com>
 *
 * Video source interface for LCD driver
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/
#ifndef __LCD_SOURCE_INTERFACE_H__
#define __LCD_SOURCE_INTERFACE_H__

#include "../bsp_display.h"

struct sunxi_lcd_drv
{
  struct sunxi_disp_source_ops      src_ops;
};

extern struct sunxi_lcd_drv g_lcd_drv;

/**
 * sunxi_lcd_delay_ms.
 * @ms: Delay time, unit: millisecond.
 */
__s32 sunxi_lcd_delay_ms(__u32 ms);

/**
 * sunxi_lcd_delay_us.
 * @us: Delay time, unit: microsecond.
 */
__s32 sunxi_lcd_delay_us(__u32 us);

/**
 * sunxi_lcd_tcon_enable - enable timing controller.
 * @screen_id: The index of screen.
 */
void sunxi_lcd_tcon_enable(__u32 screen_id);


/**
 * sunxi_lcd_tcon_disable - disable timing controller.
 * @screen_id: The index of screen.
 */
void sunxi_lcd_tcon_disable(__u32 screen_id);

/**
 * sunxi_lcd_backlight_enable - enable the backlight of panel.
 * @screen_id: The index of screen.
 */
void sunxi_lcd_backlight_enable(__u32 screen_id);

/**
 * sunxi_lcd_backlight_disable - disable the backlight of panel.
 * @screen_id: The index of screen.
 */
void sunxi_lcd_backlight_disable(__u32 screen_id);

/**
 * sunxi_lcd_power_enable - enable the power of panel.
 * @screen_id: The index of screen.
 * @pwr_id:     The index of power
 */
void sunxi_lcd_power_enable(__u32 screen_id, __u32 pwr_id);

/**
 * sunxi_lcd_power_disable - disable the power of panel.
 * @screen_id: The index of screen.
 * @pwr_id:     The index of power
 */
void sunxi_lcd_power_disable(__u32 screen_id, __u32 pwr_id);


/**
 * sunxi_lcd_pwm_set_para - config pwm parameters.
 * @pwm_channel: The index of pwm channel.
 * @pwm_info: The pointer to pwm info structure.
 */
__s32 sunxi_lcd_pwm_set_para(__u32 pwm_channel, __pwm_info_t * pwm_info);

/**
 * sunxi_pwm_get_para - get pwm parameters.
 * @pwm_channel: The index of pwm channel.
 * @pwm_info: The pointer to pwm info structure.
 */
__s32 sunxi_lcd_pwm_get_para(__u32 pwm_channel, __pwm_info_t * pwm_info);

/**
 * sunxi_pwm_set_duty_ns - config pwm active time.
 * @pwm_channel: The index of pwm channel.
 * @duty_ns: The time for pwm active period, unit: microsecond.
 */
__s32 sunxi_lcd_pwm_set_duty_ns(__u32 pwm_channel, __u32 duty_ns);

/**
 * sunxi_lcd_pwm_enable - enable pwm modules, start ouput pwm wave.
 * @pwm_channel: The index of pwm channel.
 *
 * need to conifg gpio for pwm function
 */
__s32 sunxi_lcd_pwm_enable(__u32 pwm_channel);

/**
 * sunxi_lcd_pwm_disable - disable pwm modules, stop ouput pwm wave.
 * @pwm_channel: The index of pwm channel.
 */
__s32 sunxi_lcd_pwm_disable(__u32 pwm_channel);

/**
 * sunxi_lcd_cpu_write - write command and para to cpu panel.
 * @scree_id: The index of screen.
 * @command: Command to be transfer.
 * @para: The pointer to para
 * @para_num: The number of para
 */
__s32 sunxi_lcd_cpu_write(__u32 scree_id, __u32 command, __u32 *para, __u32 para_num);

/**
 * sunxi_lcd_cpu_write_index - write command to cpu panel.
 * @scree_id: The index of screen.
 * @index: Command or index to be transfer.
 */
__s32 sunxi_lcd_cpu_write_index(__u32 scree_id, __u32 index);

/**
 * sunxi_lcd_cpu_write_data - write data to cpu panel.
 * @scree_id: The index of screen.
 * @data: Data to be transfer.
 */
__s32 sunxi_lcd_cpu_write_data(__u32 scree_id, __u32 data);

/**
 * sunxi_lcd_dsi_write - write command and para to mipi panel.
 * @scree_id: The index of screen.
 * @command: Command to be transfer.
 * @para: The pointer to para.
 * @para_num: The number of para
 */
__s32 sunxi_lcd_dsi_write(__u32 scree_id, __u8 command, __u8 *para, __u32 para_num);

/**
 * sunxi_lcd_dsi_clk_enable - enable dsi clk.
 * @scree_id: The index of screen.
 */
__s32 sunxi_lcd_dsi_clk_enable(__u32 scree_id);

/**
 * sunxi_lcd_dsi_clk_disable - disable dsi clk.
 * @scree_id: The index of screen.
 */
__s32 sunxi_lcd_dsi_clk_disable(__u32 scree_id);


/**
 * sunxi_lcd_pin_cfg - config lcd pin.
 * @scree_id: The index of screen.
 */
__s32 sunxi_lcd_pin_cfg(__u32 scree_id, __u32 en);

/**
 * sunxi_disp_get_num_screens - get number of screen supported.
 * 
 */
__s32 sunxi_disp_get_num_screens(void);


/**
 * sunxi_disp_panel_register - register panel.
 * @panel: The pointer to sunxi_panel.
 */
__s32 sunxi_lcd_get_driver_name(__u32 screen_id, char *name);

/**
 * sunxi_lcd_set_panel_funs -  set panel functions.
 * @name: The panel driver name.
 * @lcd_cfg: The functions.
 */
__s32 sunxi_lcd_set_panel_funs(char *name, __lcd_panel_fun_t * lcd_cfg);

/**
 * sunxi_lcd_get_panel_para -  set panel functions.
 * @screen_id: The index of screen
 * @info: Para of panel
 */
__s32 sunxi_lcd_get_panel_para(__u32 screen_id, __panel_para_t * info);


/**
 * sunxi_lcd_iic_write -  .
 * @slave_addr: Slave device address
 * @sub_aadr:   
 * @value: Value to be write
 */
__s32 sunxi_lcd_iic_write(__u8 slave_addr, __u8 sub_addr, __u8 value);


/**
 * sunxi_lcd_iic_read -  .
 * @slave_addr: Slave device address
 * @sub_aadr:   
 * @value: The pointer of value read back
 */
__s32 sunxi_lcd_iic_read(__u8 slave_addr, __u8 sub_addr, __u8 *value);

#endif
