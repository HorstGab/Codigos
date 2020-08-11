package view;

import java.awt.Color;
import java.awt.Component;
import java.awt.Font;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.Icon;
import javax.swing.JLabel;
import javax.swing.JTable;
import javax.swing.SwingConstants;
import javax.swing.UIManager;
import javax.swing.border.Border;
import javax.swing.border.EmptyBorder;
import javax.swing.table.TableCellRenderer;

public class CellRenderer extends JLabel implements TableCellRenderer {
		private static final long serialVersionUID = 7827312845479290067L;

		protected int verticalAlignment;
		protected int horizontalAlignment;
		protected float alignmentX;
		protected Color foreground;
		protected Color background;
		protected Font font;
		protected static Border border = new EmptyBorder(1, 2, 1, 2);

		private static final Color COLOR_BG_DEFAULT = Color.decode( "#fefefe" );
				//Color.decode("#ffffcc");
		private static final Color COLOR_BG_ALTERNATE = Color.decode( "#d8edf8" ); //Color.YELLOW;
		private static final Color COLOR_FG_DEFAULT = Color.BLACK;

		public CellRenderer(int horizontalAlignment, int verticalAlignment) {
			this.horizontalAlignment = horizontalAlignment;
			this.verticalAlignment = verticalAlignment;
			switch (horizontalAlignment) {
			case SwingConstants.LEFT:
				alignmentX = (float) 0.0;
				break;

			case SwingConstants.CENTER:
				alignmentX = (float) 0.5;
				break;

			case SwingConstants.RIGHT:
				alignmentX = (float) 1.0;
				break;

			default:
				throw new IllegalArgumentException(
						"Illegal horizontal alignment value");
			}

			setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
			setOpaque(true);
			setBorder(border);
		}

		@Override
		public Component getTableCellRendererComponent(JTable table, Object value,
				boolean isSelected, boolean hasFocus, int row, int column) {
			removeAll();
			invalidate();

			if (value == null || table == null) {
				// Do nothing if no value
				return this;
			}

			// Get default values for back and foreground
			Color cellForeground = COLOR_FG_DEFAULT;
			Color cellBackground = COLOR_BG_DEFAULT;

			// Enable alternate background colors
			if (row % 2 != 0) {
				cellBackground = COLOR_BG_ALTERNATE;
			}

			// Handle selection and focus colors
			if (isSelected) {
				cellForeground = table.getSelectionForeground();
				cellBackground = table.getSelectionBackground();
			}

			// Handle focus colors
			if (hasFocus == true) {
				setBorder(UIManager.getBorder("Table.focusCellHighlightBorder"));
				if (table.isCellEditable(row, column)) {
					cellForeground = UIManager
							.getColor("Table.focusCellForeground");
					cellBackground = UIManager
							.getColor("Table.focusCellBackground");
				}
			} else {
				setBorder(border);
			}

			// Alignment
			if (verticalAlignment != SwingConstants.TOP) {
				add(Box.createVerticalGlue());
			}
			// Add Value to cell as a JLabel
			JLabel item = new JLabel();
			setValue(item, value, row, cellForeground);
			add(item);
			// Alignment
			if (verticalAlignment != SwingConstants.BOTTOM) {
				add(Box.createVerticalGlue());
			}

			// Finally apply fore and background colors
			setForeground(cellForeground);
			setBackground(cellBackground);

			return this;
		}

		@Override
		public void setBackground(Color background) {
			this.background = background;
			super.setBackground(background);
		}

		@Override
		public void setFont(Font font) {
			this.font = font;
		}

		@Override
		public Font getFont() {
			if (this.font == null)
				return super.getFont();
			else
				return this.font;
		}

		@Override
		public void setForeground(Color foreground) {
			super.setForeground(foreground);
			Component[] comps = this.getComponents();
			int ncomp = comps.length;
			for (int i = 0; i < ncomp; i++) {
				Component comp = comps[i];
				if (comp instanceof JLabel) {
					comp.setForeground(foreground);
				}
			}
		}

		protected void setValue(JLabel l, Object value, int lineNumber,
				Color cellForeground) {
			if (value != null && value instanceof Icon) {
				l.setIcon((Icon) value);
			} else {
				l.setText(value == null ? "" : value.toString());
			}
			l.setHorizontalAlignment(horizontalAlignment);
			l.setAlignmentX(alignmentX);
			l.setOpaque(false);
			l.setForeground(cellForeground);
			l.setFont(font);
		}
}
