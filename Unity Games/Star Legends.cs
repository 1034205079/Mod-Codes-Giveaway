//Game: Star Legends (Dreamsky)3D PVP
//Version: 1.1.5
//APK: https://apkcombo.com/en-gb/apk-downloader/?q=com.dr.xjlh1

//Bilinkeji.NewPk.Core Mecha x20 dmg
public override float GetDamagePercentage()
		{
			if (Team.Black1)
			{
				return 20f;
			}
		
			return 1f + StarLegends.dmgMulti;
		
			return 1f;
		}
		
		
//Bilinkeji.NewPk.Core Skill  No cd
public void SetTotalCd(float value)
		{
			if (StarLegends.toggle2)
			{
				value = 0f;
			}
			this._cdTotal = value;
		}
		
		 No SP cost
		public void SetCost(SkillCostType cType, int value)
		{
			if (StarLegends.toggle3)
			{
				value = 0;
			}
			this._costType = cType;
			this._mpCost = value;
		}
		
//Bilinkeji.NewPk.Core Role God mode
public bool IsInvincibility()
		{
			if (StarLegends.toggle4 && this.GetRoleType() == RoleType.Mecha)
			{
				return true;
			}
			for (int i = 0; i < this.buffList.Count; i++)
			{
				if (this.buffList[i].buffConfig.buffTypeId == 10 || this.buffList[i].buffConfig.buffTypeId == 12)
				{
					return true;
				}
			}
			return false;
		}
		
//AudioManager
public void OnGUI()
	{
		StarLegends.OnGUI();
	}