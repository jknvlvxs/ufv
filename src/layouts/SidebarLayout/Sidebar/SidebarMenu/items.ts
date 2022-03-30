import DesignServicesTwoToneIcon from '@mui/icons-material/DesignServicesTwoTone';
import PersonTwoToneIcon from '@mui/icons-material/PersonTwoTone';
import DescriptionTwoToneIcon from '@mui/icons-material/DescriptionTwoTone';
import { ReactNode } from 'react';

export interface MenuItem {
  link?: string;
  icon?: ReactNode;
  badge?: string;
  items?: MenuItem[];
  name: string;
}

export interface MenuItems {
  items: MenuItem[];
  heading: string;
}

const menuItems: MenuItems[] = [
  {
    heading: '',
    items: [
      {
        name: 'Início',
        link: '/dashboards/home',
        icon: DesignServicesTwoToneIcon,
      },
    ],
  },
  {
    heading: 'Gerenciamento',
    items: [
      {
        name: 'Hotéis',
        icon: PersonTwoToneIcon,
        link: '/management/clients',
      },
      {
        name: 'Tipos de Apartamentos',
        icon: PersonTwoToneIcon,
        link: '/management/clients',
      },
      {
        name: 'Clientes',
        icon: PersonTwoToneIcon,
        link: '/management/clients',
      },
      {
        name: 'Reservas',
        icon: PersonTwoToneIcon,
        link: '/management/clients',
      },
      {
        name: 'Hospedagem',
        icon: PersonTwoToneIcon,
        link: '/management/clients',
      },
      {
        name: 'Contratos',
        icon: DescriptionTwoToneIcon,
        link: '/management/contracts',
      },
    ],
  },
];

export default menuItems;
